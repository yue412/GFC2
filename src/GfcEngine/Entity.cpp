#include <Windows.h>
#include <string>
#include <assert.h>
#include "GfcEngine/Entity.h"
#include "GfcEngine/EngineException.h"
#include "GfcEngine/Document.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "EntityAttributeDataHandler.h"
#include "Common.h"

GFCENGINE_NAMESPACE_BEGIN

Entity::Entity(void): m_pDocument(nullptr), m_pClass(nullptr), m_pData(nullptr)
{
}

Entity::~Entity(void)
{
    free();
}

void Entity::setDocument( Document* pDocument )
{
    m_pDocument = pDocument;
}

void Entity::setSchema(gfc2::schema::CClass * pClass)
{
    assert(pClass);
    if (pClass != m_pClass)
    {
        free();
        m_pClass = pClass;
        init();
    }
}

bool Entity::isInitialized() const
{
    if (m_pClass)
    {
        for (int i = 0; i < m_pClass->getAttributeCount(); i++)
        {
            auto pAttr = m_pClass->getAttribute(i);
            if (!pAttr->getOptionalFlag() && ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->isNull(m_pData))
                return false;
        }
    }
    return true;
}

int Entity::getPropCount() const
{
    return m_pClass ? m_pClass->getAttributeCount() : 0;
}

PropertyPtr Entity::getProps(int nIndex) const
{
    Property* pResult = nullptr;
    if (m_pClass && nIndex < getPropCount())
    {
        pResult = new Property(m_pData, m_pClass->getAttribute(nIndex));
    }
    return PropertyPtr(pResult);
}

bool Entity::isNull(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->isNull(m_pData);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return true;
}

std::string Entity::entityName() const
{
    assert(m_pClass);
    return toString(m_pClass->getName());
}

void Entity::init()
{
    if (m_pClass)
    {
        auto nLen = m_pClass->getDataSize();
        m_pData = new char[nLen];
        ZeroMemory(m_pData, nLen);
        for (int i = 0; i < m_pClass->getAttributeCount(); i++)
        {
            auto pAttr = m_pClass->getAttribute(i);
            pAttr->getDataHandler()->init(m_pData);
        }
    }
}

void Entity::free()
{
    if (m_pClass)
    {
        for (int i = 0; i < m_pClass->getAttributeCount(); i++)
        {
            auto pAttr = m_pClass->getAttribute(i);
            pAttr->getDataHandler()->free(m_pData);
        }
    }
    delete[] m_pData;
    m_pData = nullptr;
}

std::string Entity::asString(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asString(m_pData);
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
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asInteger(m_pData);
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
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asDouble(m_pData);
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
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asBoolean(m_pData);
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
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asEntityRef(m_pData);
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
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->setAsString(m_pData, sValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsInteger(const std::string& sPropName, const int& nValue)
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->setAsInteger(m_pData, nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsDouble(const std::string& sPropName, const double& dValue)
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->setAsDouble(m_pData, dValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsBoolean(const std::string& sPropName, const bool& bValue)
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->setAsBoolean(m_pData, bValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void Entity::setAsEntityRef(const std::string& sPropName, const EntityRef& nValue)
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->setAsEntityRef(m_pData, nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

std::vector<std::string>& Entity::asStringList(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asStringList(m_pData);
        }
    }
    throw EMissMatchProperty();
}

std::vector<int>& Entity::asIntegerList(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asIntegerList(m_pData);
        }
    }
    throw EMissMatchProperty();
}

std::vector<double>& Entity::asDoubleList(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asDoubleList(m_pData);
        }
    }
    throw EMissMatchProperty();
}

std::vector<bool>& Entity::asBooleanList(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asBooleanList(m_pData);
        }
    }
    throw EMissMatchProperty();
}

std::vector<EntityRef>& Entity::asEntityRefList(const std::string& sPropName) const
{
    if (m_pClass)
    {
        auto pAttr = m_pClass->findAttribute(toWstring(sPropName));
        if (pAttr)
        {
            return ((EntityAttributeDataHandler*)(pAttr->getDataHandler()))->asEntityRefList(m_pData);
        }
    }
    throw EMissMatchProperty();
}

GFCENGINE_NAMESPACE_END
