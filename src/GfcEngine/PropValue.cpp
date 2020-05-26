#include "GfcEngine\PropValue.h"
#include "GfcEngine\EngineException.h"

GFCENGINE_NAMESPACE_BEGIN

PropValue::PropValue()
{
}


PropValue::~PropValue()
{
}

std::string PropValue::asString() const
{
    throw ETypeMatchError();
}

int PropValue::asInteger() const
{
    throw ETypeMatchError();
}

double PropValue::asDouble() const
{
    throw ETypeMatchError();
}

bool PropValue::asBoolean() const
{
    throw ETypeMatchError();
}

EntityRef PropValue::asEntityRef() const
{
    throw ETypeMatchError();
}

Entity* PropValue::asEntity() const
{
    throw ETypeMatchError();
}

void PropValue::setAsString(const std::string& sValue)
{
    throw ETypeMatchError();
}

void PropValue::setAsInteger(const int& nValue)
{
    throw ETypeMatchError();
}

void PropValue::setAsDouble(const double& dValue)
{
    throw ETypeMatchError();
}

void PropValue::setAsBoolean(const bool& bValue)
{
    throw ETypeMatchError();
}

void PropValue::setAsEntityRef(const EntityRef& nValue)
{
    throw ETypeMatchError();
}

CompositePropValue::CompositePropValue()
{
}

CompositePropValue::~CompositePropValue()
{
    clear();
}

void CompositePropValue::add(PropValue* pValue)
{
    m_oList.push_back(pValue);
}

void CompositePropValue::setItems(int nIndex, PropValue* pValue)
{
    auto pOldValue = getItems(nIndex);
    delete pOldValue;
    m_oList[nIndex] = pValue;
}

void CompositePropValue::clear()
{
    for each (auto pValue in m_oList)
    {
        delete pValue;
    }
    m_oList.clear();
}

int BooleanValue::asInteger() const
{
    return asBoolean();
}

double BooleanValue::asDouble() const
{
    return asInteger();
}

bool BooleanValue::asBoolean() const
{
    return m_bValue;
}

void BooleanValue::setAsInteger(const int & nValue)
{
    setAsBoolean(nValue != 0);
}

void BooleanValue::setAsBoolean(const bool & bValue)
{
    m_bValue = bValue;
    setIsNull(false);
}

int IntegerValue::asInteger() const
{
    return m_nValue;
}

double IntegerValue::asDouble() const
{
    return asInteger();
}

bool IntegerValue::asBoolean() const
{
    return asInteger() != 0;
}

void IntegerValue::setAsInteger(const int & nValue)
{
    m_nValue = nValue;
    setIsNull(false);
}

void IntegerValue::setAsBoolean(const bool & bValue)
{
    setAsInteger(bValue);
}

double DoubleValue::asDouble() const
{
    return m_dValue;
}

void DoubleValue::setAsInteger(const int & nValue)
{
    setAsDouble(nValue);
}

void DoubleValue::setAsDouble(const double & dValue)
{
    m_dValue = dValue;
    setIsNull(false);
}

void DoubleValue::setAsBoolean(const bool & bValue)
{
    setAsDouble(bValue);
}

std::string StringValue::asString() const
{
    return m_sValue;
}

void StringValue::setAsString(const std::string & sValue)
{
    m_sValue = sValue;
    setIsNull(false);
}

void StringValue::setAsInteger(const int & nValue)
{
    setAsString(std::to_string(nValue));
}

void StringValue::setAsDouble(const double & dValue)
{
    setAsString(std::to_string(dValue));
}

void StringValue::setAsBoolean(const bool & bValue)
{
    setAsString(std::to_string(bValue));
}

EntityRef EntityRefValue::asEntityRef() const
{
    return m_nValue;
}

void EntityRefValue::setAsEntityRef(const EntityRef & nValue)
{
    m_nValue = nValue;
    setIsNull(false);
}

GFCENGINE_NAMESPACE_END
