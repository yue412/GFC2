#include "GfcEngine\PropValue.h"
#include "GfcEngine\EngineException.h"
#include "Common.h"
#include <sstream>
#include <iomanip>

GFCENGINE_NAMESPACE_BEGIN

CPropValue::CPropValue()
{
}


CPropValue::~CPropValue()
{
}

std::wstring CPropValue::asString() const
{
    throw ETypeMatchError();
}

int CPropValue::asInteger() const
{
    throw ETypeMatchError();
}

double CPropValue::asDouble() const
{
    throw ETypeMatchError();
}

bool CPropValue::asBoolean() const
{
    throw ETypeMatchError();
}

EntityRef CPropValue::asEntityRef() const
{
    throw ETypeMatchError();
}

void CPropValue::setAsString(const std::wstring& sValue)
{
    throw ETypeMatchError();
}

void CPropValue::setAsInteger(const int& nValue)
{
    throw ETypeMatchError();
}

void CPropValue::setAsDouble(const double& dValue)
{
    throw ETypeMatchError();
}

void CPropValue::setAsBoolean(const bool& bValue)
{
    throw ETypeMatchError();
}

void CPropValue::setAsEntityRef(const EntityRef& nValue)
{
    throw ETypeMatchError();
}

std::wstring CPropValue::toString() const
{
    return isNull() ? L"$" : innerToString();
}

CCompositePropValue::CCompositePropValue()
{
}

CCompositePropValue::~CCompositePropValue()
{
    clear();
}

void CCompositePropValue::add(CPropValue* pValue)
{
    m_oList.push_back(pValue);
}

CPropValue * CCompositePropValue::getItems(int nIndex) const
{
    if (inRange(nIndex))
        return m_oList[nIndex];
    else
        return nullptr;
}

void CCompositePropValue::setItems(int nIndex, CPropValue* pValue)
{
    if (inRange(nIndex))
    {
        auto pOldValue = getItems(nIndex);
        delete pOldValue;
        m_oList[nIndex] = pValue;
    }
}

void CCompositePropValue::clear()
{
    for each (auto pValue in m_oList)
    {
        delete pValue;
    }
    m_oList.clear();
}

CPropValue * CCompositePropValue::clone() const
{
    CCompositePropValue* pCompositeValue = new CCompositePropValue();
    for each (auto pValue in m_oList)
    {
        pCompositeValue->add(pValue->clone());
    }
    return pCompositeValue;
}

void CCompositePropValue::assign(CPropValue * pValue)
{
    assert(pValue);
    clear();
    for (int i = 0; i < pValue->getCount(); i++)
    {
        add(pValue->getItems(i)->clone());
    }
}

std::wstring CCompositePropValue::innerToString() const
{
    std::wstring sResult = L"(";
    for (int j = 0; j < getCount() - 1; ++j)
    {
        sResult += getItems(j)->toString() + L",";
    }
    sResult += getItems(getCount() - 1)->toString() + L")";
    return sResult;
}

bool CCompositePropValue::inRange(int nIndex) const
{
    return nIndex >= 0 && nIndex < getCount();
}

int CBooleanValue::asInteger() const
{
    return asBoolean();
}

double CBooleanValue::asDouble() const
{
    return asInteger();
}

bool CBooleanValue::asBoolean() const
{
    return m_bValue;
}

void CBooleanValue::setAsInteger(const int & nValue)
{
    setAsBoolean(nValue != 0);
}

void CBooleanValue::setAsBoolean(const bool & bValue)
{
    m_bValue = bValue;
    setIsNull(false);
}

std::wstring CBooleanValue::innerToString() const
{
    return std::to_wstring(asInteger());
}

int CIntegerValue::asInteger() const
{
    return m_nValue;
}

double CIntegerValue::asDouble() const
{
    return asInteger();
}

bool CIntegerValue::asBoolean() const
{
    return asInteger() != 0;
}

void CIntegerValue::setAsInteger(const int & nValue)
{
    m_nValue = nValue;
    setIsNull(false);
}

void CIntegerValue::setAsBoolean(const bool & bValue)
{
    setAsInteger(bValue);
}

std::wstring CIntegerValue::innerToString() const
{
    return std::to_wstring(asInteger());
}

double CDoubleValue::asDouble() const
{
    return m_dValue;
}

void CDoubleValue::setAsInteger(const int & nValue)
{
    setAsDouble(nValue);
}

void CDoubleValue::setAsDouble(const double & dValue)
{
    m_dValue = dValue;
    setIsNull(false);
}

void CDoubleValue::setAsBoolean(const bool & bValue)
{
    setAsDouble(bValue);
}

std::wstring CDoubleValue::innerToString() const
{
    std::wstringstream ss;
    ss << std::setprecision(15) << asDouble();
    return ss.str();
}

std::wstring CStringValue::asString() const
{
    return m_sValue;
}

void CStringValue::setAsString(const std::wstring & sValue)
{
    m_sValue = sValue;
    setIsNull(false);
}

std::wstring CStringValue::innerToString() const
{
    return L"'" + transString(m_sValue) + L"'";
}

//void CStringValue::setAsInteger(const int & nValue)
//{
//    setAsString(std::to_string(nValue));
//}
//
//void CStringValue::setAsDouble(const double & dValue)
//{
//    setAsString(std::to_string(dValue));
//}
//
//void CStringValue::setAsBoolean(const bool & bValue)
//{
//    setAsString(std::to_string(bValue));
//}

EntityRef CEntityRefValue::asEntityRef() const
{
    return m_nValue;
}

void CEntityRefValue::setAsEntityRef(const EntityRef & nValue)
{
    m_nValue = nValue;
    setIsNull(false);
}

std::wstring CEntityRefValue::innerToString() const
{
    return std::to_wstring(asEntityRef());
}

GFCENGINE_NAMESPACE_END
