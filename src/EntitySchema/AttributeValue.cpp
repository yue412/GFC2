#include "AttributeValue.h"

GFC_NAMESPACE_BEGIN

CAttributeValue::CAttributeValue()
{
}


CAttributeValue::~CAttributeValue()
{
}

CLeafAttributeValue::CLeafAttributeValue()
{
}

CLeafAttributeValue::CLeafAttributeValue(const std::wstring & sValue): m_sValue(sValue)
{
}

CLeafAttributeValue::~CLeafAttributeValue()
{
}

std::wstring CLeafAttributeValue::asString()
{
    return m_sValue;
}

void CLeafAttributeValue::setAsString(const std::wstring & sValue)
{
    m_sValue = sValue;
}

CCompositeAttributeValue::CCompositeAttributeValue()
{
}

CCompositeAttributeValue::~CCompositeAttributeValue()
{
    clear();
}

std::wstring CCompositeAttributeValue::asString()
{
    if (getCount() == 0)
    {
        return L"$";
    }
    else
    {
        std::wstring sResult;
        for each (auto pValue in m_oList)
        {
            sResult += pValue->asString() + L",";
        }
        return L"(" + sResult.substr(0, sResult.length() - 1) + L")";
    }
}

void CCompositeAttributeValue::add(CAttributeValuePtr pValue)
{
    m_oList.push_back(pValue);
}

void CCompositeAttributeValue::setItems(int nIndex, CAttributeValuePtr pValue)
{
    //auto pOldValue = getItems(nIndex);
    //delete pOldValue;
    m_oList[nIndex] = pValue;
}

void CCompositeAttributeValue::clear()
{
    //for each (auto pValue in m_oList)
    //{
    //    delete pValue;
    //}
    m_oList.clear();
}

GFC_NAMESPACE_END
