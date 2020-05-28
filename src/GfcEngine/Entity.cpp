#include <Windows.h>
#include <string>
#include <assert.h>
#include "GfcEngine/Entity.h"
#include "GfcEngine/EngineException.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Property.h"
#include "GfcEngine\PropValue.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "Common.h"

GFCENGINE_NAMESPACE_BEGIN

Entity::Entity(void): m_pDocument(nullptr), m_pSchema(nullptr), m_pProps(nullptr)
{
    m_pProps = new std::vector<Property*>();
}

Entity::~Entity(void)
{
    free();
    delete m_pProps;
}

void Entity::setDocument( Document* pDocument )
{
    m_pDocument = pDocument;
}

void Entity::setSchema(gfc2::schema::CTypeObject * pType)
{
    assert(pType);
    if (pType != m_pSchema && pType->getDataType() == gfc2::schema::EDT_ENTITY)
    {
        free();
        m_pSchema = pType;
        init();
    }
}

gfc2::schema::CClass * Entity::getClass() const
{
    if (m_pSchema)
    {
        return (gfc2::schema::CClass *)m_pSchema->getBaseType();
    }
    return nullptr;
}

bool Entity::isInitialized() const
{
    if (m_pSchema)
    {
        for (int i = 0; i < getClass()->getAttributeCount(); i++)
        {
            auto pAttr = getClass()->getAttribute(i);
            if (!pAttr->getOptionalFlag() && getProps(i)->value()->isNull())
                return false;
        }
    }
    return true;
}

int Entity::getPropCount() const
{
    return m_pSchema ? getClass()->getAttributeCount() : 0;
}

Property* Entity::getProps(int nIndex) const
{
    return (*m_pProps)[nIndex];
}

bool Entity::isNull(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->isNull();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return true;
}

PropValue * Entity::valueByName(const std::string sPropName) const
{
    if (m_pSchema)
    {
        auto nIndex = getClass()->attributeIndexByName(toWstring(sPropName));
        if (nIndex >= 0)
        {
            return getProps(nIndex)->value();
        }
    }
    return nullptr;
}

std::string Entity::entityName() const
{
    assert(m_pSchema);
    return toString(m_pSchema->getName());
}

void Entity::init()
{
    if (m_pSchema)
    {
        for (int i = 0; i < getClass()->getAttributeCount(); i++)
        {
            auto pAttr = getClass()->getAttribute(i);
            if (pAttr->getRepeatFlag())
            {
                m_pProps->push_back(new Property(pAttr, new CompositePropValue));
            }
            else
            {
                m_pProps->push_back(new Property(pAttr, Property::createValue(pAttr->getType())));
            }
        }
    }
}

void Entity::free()
{
    for each (auto pProp in *m_pProps)
    {
        delete pProp;
    }
    m_pProps->clear();
}

std::string Entity::asString(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asString();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return "";
}

int Entity::asInteger(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asInteger();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0;
}

double Entity::asDouble(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asDouble();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0.0;
}

bool Entity::asBoolean(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asBoolean();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return false;
}

EntityRef Entity::asEntityRef(const std::string& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asEntityRef();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return -1;
}

Entity* Entity::asEntity(const std::string& sPropName) const
{
    //todo
    return nullptr;
}

void Entity::setAsString(const std::string& sPropName, const std::string& sValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsString(sValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsInteger(const std::string& sPropName, const int& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsInteger(nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsDouble(const std::string& sPropName, const double& dValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsDouble(dValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsBoolean(const std::string& sPropName, const bool& bValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsBoolean(bValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsEntityRef(const std::string& sPropName, const EntityRef& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsEntityRef(nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

GFCENGINE_NAMESPACE_END
