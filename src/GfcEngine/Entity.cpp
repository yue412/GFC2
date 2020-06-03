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

GFCENGINE_IMP_FACTORY(Entity, 0)

Entity::Entity(void): m_pContainer(nullptr), m_pSchema(nullptr), m_pProps(nullptr)
{
    m_pProps = new std::vector<Property*>();
}

Entity::~Entity(void)
{
    free();
    delete m_pProps;
}

void Entity::setContainer( IContainer* pContainer )
{
    m_pContainer = pContainer;
}

void Entity::setSchema(gfc2::schema::CTypeObject * pType)
{
    assert(pType);
    assert(pType->getDataType() == gfc2::schema::EDT_ENTITY);
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
            if (!pAttr->getOptionalFlag() && !pAttr->getRepeatFlag() && getProps(i)->value()->isNull())
                return false;
        }
    }
    return true;
}

int Entity::getPropCount() const
{
    return (int)m_pProps->size();
}

Property* Entity::getProps(int nIndex) const
{
    if (nIndex < (int)m_pProps->size() && nIndex >= 0)
        return (*m_pProps)[nIndex];
    else
        return nullptr;
}

Property * Entity::propByName(const std::wstring sPropName) const
{
    if (m_pSchema)
    {
        auto pClass = getClass();
        int nIndex = -1;
        while (pClass)
        {
            auto pParent = pClass->getParent();
            nIndex = pClass->attributeIndexByName(sPropName);
            if (nIndex >= 0)
            {
                nIndex += pParent ? pParent->getTotalAttributeCount() : 0;
                break;
            }
            pClass = pParent;
        }
        return getProps(nIndex);
    }
    return nullptr;
}

bool Entity::isNull(const std::wstring& sPropName) const
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

PropValue * Entity::valueByName(const std::wstring sPropName) const
{
    auto pProperty = propByName(sPropName);
    if (pProperty)
        return pProperty->value();
    else
        return nullptr;
}

std::wstring Entity::entityName() const
{
    assert(m_pSchema);
    return m_pSchema->getName();
}

void Entity::init()
{
    initProps(getClass());
}

void Entity::initProps(gfc2::schema::CClass* pClass)
{
    if (pClass)
    {
        initProps(pClass->getParent());
        for (int i = 0; i < pClass->getAttributeCount(); i++)
        {
            auto pAttr = pClass->getAttribute(i);
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

std::string Entity::asString(const std::wstring& sPropName) const
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

int Entity::asInteger(const std::wstring& sPropName) const
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

double Entity::asDouble(const std::wstring& sPropName) const
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

bool Entity::asBoolean(const std::wstring& sPropName) const
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

EntityRef Entity::asEntityRef(const std::wstring& sPropName) const
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

EntityPtr Entity::asEntity(const std::wstring& sPropName) const
{
    if (m_pSchema && m_pContainer)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return m_pContainer->getEntity(pValue->asEntityRef());
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return nullptr;
}

void Entity::setAsString(const std::wstring& sPropName, const std::string& sValue)
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

void Entity::setAsInteger(const std::wstring& sPropName, const int& nValue)
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

void Entity::setAsDouble(const std::wstring& sPropName, const double& dValue)
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

void Entity::setAsBoolean(const std::wstring& sPropName, const bool& bValue)
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

void Entity::setAsEntityRef(const std::wstring& sPropName, const EntityRef& nValue)
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

int Entity::getArrayCount(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->getCount();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0;
}

void Entity::addEntityRef(const std::wstring& sPropName, const EntityRef& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new EntityRefValue(nValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::addString(const std::wstring& sPropName, const std::string& sValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new StringValue(sValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::addInteger(const std::wstring& sPropName, const int& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new IntegerValue(nValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::addDouble(const std::wstring& sPropName, const double& dValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new DoubleValue(dValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::addBoolean(const std::wstring& sPropName, const bool& bValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new BooleanValue(bValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

std::string Entity::getString(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asString() : "";
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return "";
}

int Entity::getInteger(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asInteger() : 0;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0;
}

double Entity::getDouble(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asDouble() : 0.0;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0.0;
}

bool Entity::getBoolean(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asBoolean() : false;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return false;
}

EntityRef Entity::getEntityRef(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asEntityRef() : -1;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return -1;
}

EntityPtr Entity::getEntity(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema && m_pContainer)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return m_pContainer->getEntity(pVal ? pVal->asEntityRef() : -1);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return nullptr;
}

GFCENGINE_NAMESPACE_END
