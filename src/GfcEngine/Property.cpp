#include "GfcEngine\Property.h"
#include "EntityAttribute.h"
#include "Common.h"
#include "EntityAttributeDataHandler.h"

GFCENGINE_NAMESPACE_BEGIN

Property::Property(char* pData, gfc2::schema::CAttribute* pAttribute): m_pData(pData), m_pAttribute(pAttribute)
{
}

Property::~Property()
{
}

std::string Property::propName() const
{
    return toString(m_pAttribute->getName());
}

bool Property::isNull() const
{
    return getDataHandler()->isNull(m_pData);
}

std::string Property::asString() const
{
    return getDataHandler()->asString(m_pData);
}

int Property::asInteger() const
{
    return getDataHandler()->asInteger(m_pData);
}

double Property::asDouble() const
{
    return getDataHandler()->asDouble(m_pData);
}

bool Property::asBoolean() const
{
    return getDataHandler()->asBoolean(m_pData);
}

EntityRef Property::asEntityRef() const
{
    return getDataHandler()->asEntityRef(m_pData);
}

Entity* Property::asEntity() const
{
    //todo
    return nullptr;
}

void Property::setAsString(const std::string& sValue)
{
    getDataHandler()->setAsString(m_pData, sValue);
}

void Property::setAsInteger(const int& nValue)
{
    getDataHandler()->setAsInteger(m_pData, nValue);
}

void Property::setAsDouble(const double& dValue)
{
    getDataHandler()->setAsDouble(m_pData, dValue);
}

void Property::setAsBoolean(const bool& bValue)
{
    getDataHandler()->setAsBoolean(m_pData, bValue);
}

void Property::setAsEntityRef(const EntityRef& nValue)
{
    getDataHandler()->setAsEntityRef(m_pData, nValue);
}

std::vector<std::string>& Property::asStringList() const
{
    return getDataHandler()->asStringList(m_pData);
}

std::vector<int>& Property::asIntegerList() const
{
    return getDataHandler()->asIntegerList(m_pData);
}

std::vector<double>& Property::asDoubleList() const
{
    return getDataHandler()->asDoubleList(m_pData);
}

std::vector<bool>& Property::asBooleanList() const
{
    return getDataHandler()->asBooleanList(m_pData);
}

std::vector<EntityRef>& Property::asEntityRefList() const
{
    return getDataHandler()->asEntityRefList(m_pData);
}

EntityAttributeDataHandler * Property::getDataHandler() const
{
    return (EntityAttributeDataHandler*)(m_pAttribute->getDataHandler());
}

GFCENGINE_NAMESPACE_END