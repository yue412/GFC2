#include "Converter.h"
#include "GfcSchema\EnumType.h"

GFC_NAMESPACE_BEGIN

const wchar_t* c_sEmptyFlag = L"$";

CConverter::~CConverter()
{
    delete m_pNext;
}

void CConverter::transform(CAttributeValuePtr& pValue)
{
    if (m_pNext)
        m_pNext->transform(pValue);
    doTransform(pValue);
}

void CConverter::setNext(CConverter * pNext)
{
    delete m_pNext;
    m_pNext = pNext;
}

void CConverter::init(CTypeObject * pFrom, CTypeObject * pTo)
{
    m_pFrom = pFrom;
    m_pTo = pTo;
    if (m_pNext)
        m_pNext->init(pFrom, pTo);
}

std::wstring CConverter::enclosedInQuotes(const std::wstring & sValue)
{
    return L"'" + sValue + L"'";
}

std::wstring CConverter::enclosedInDot(const std::wstring & sValue)
{
    return L"." + sValue + L".";
}

std::wstring CConverter::enclosedInBrackets(const std::wstring & sValue)
{
    return L"(" + sValue + L")";;
}

std::wstring CConverter::intToEnum(int nIndex)
{
    auto pEnum = dynamic_cast<CEnumType*>(m_pTo);
    return pEnum && pEnum->getEnumCount() > 0 ? enclosedInDot(pEnum->getEnum(abs(nIndex) % pEnum->getEnumCount())) : c_sEmptyFlag;
}

int CConverter::enumToInt(const std::wstring & sValue)
{
    auto sVal = dropDot(sValue);
    auto pEnum = dynamic_cast<CEnumType*>(m_pFrom);
    return pEnum ? pEnum->indexOf(sVal) : -1;
}

std::wstring CConverter::intToBool(int nIndex)
{
    return nIndex != 0 ? L".T." : L".F.";
}

std::wstring CConverter::dropDot(const std::wstring & sValue)
{
    // 去掉枚举值左右的点
    return sValue.substr(1, sValue.length() - 2);
}

void CCopyConverter::doTransform(CAttributeValuePtr& pValue)
{
    // do nothing
}
void CEnumConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto pEnum = dynamic_cast<CEnumType*>(m_pTo);
    if (!pEnum || !pEnum->exists(dropDot(pValue->asString())))
    {
        pValue->setAsString(c_sEmptyFlag);
    }
}

void CEmptyConverter::doTransform(CAttributeValuePtr& pValue)
{
    pValue->setAsString(c_sEmptyFlag);
}

void CBoolToIntConverter::doTransform(CAttributeValuePtr& pValue)
{
    pValue->setAsString(std::to_wstring(boolToInt(pValue->asString())));
}

void CBoolToStringConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto sValue = pValue->asString();
    sValue = std::to_wstring(boolToInt(sValue));
    sValue = enclosedInQuotes(sValue);
    pValue->setAsString(sValue);
}

void CBoolToEnumConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nIndex = boolToInt(pValue->asString());
    pValue->setAsString(intToEnum(nIndex));
}

void CIntToBoolConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nValue = std::stoi(pValue->asString());
    pValue->setAsString(intToBool(nValue));
}

void CStringConverter::doTransform(CAttributeValuePtr& pValue)
{
    pValue->setAsString(enclosedInQuotes(pValue->asString()));
}

void CIntToEnumConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nIndex = std::stoi(pValue->asString());
    pValue->setAsString(intToEnum(nIndex));
}

void CEnumToBoolConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nIndex = enumToInt(pValue->asString());
    pValue->setAsString(nIndex == -1 ? c_sEmptyFlag : intToBool(nIndex));
}

void CEnumToIntConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nIndex = enumToInt(pValue->asString());
    pValue->setAsString(nIndex == -1 ? c_sEmptyFlag : std::to_wstring(nIndex));
}

void CEnumToStringConverter::doTransform(CAttributeValuePtr& pValue)
{
    auto nIndex = enumToInt(pValue->asString());
    pValue->setAsString(nIndex == -1 ? c_sEmptyFlag : enclosedInQuotes(std::to_wstring(nIndex)));
}

void CArrayToArrayConverter::transform(CAttributeValuePtr& pValue)
{
    for (int i = 0; i < pValue->getCount(); i++)
    {
        auto pItem = pValue->getItems(i);
        if (pItem->asString() != c_sEmptyFlag)
        {
            CConverter::transform(pItem);
            pValue->setItems(i, pItem);
        }
    }
    //if (pValue->getCount() != 0)
    //{
    //    std::wstring sResult;
    //    auto str = dropDot(sValue) + L",";
    //    std::size_t nStart = 0;
    //    auto nPos = str.find(L',');
    //    while (nPos != std::wstring::npos)
    //    {
    //        auto sVal = str.substr(nStart, nPos - nStart);
    //        if (sVal != c_sEmptyFlag)
    //            CConverter::transform(sVal);
    //        sResult += sVal + L",";
    //        nStart = nPos + 1;
    //        nPos = str.find(L',', nStart);
    //    }
    //    sValue = enclosedInBrackets(sResult.substr(0, sResult.length() - 1));
    //}
}

void CArrayToArrayConverter::doTransform(CAttributeValuePtr& pValue)
{
    //do nothing
}

void COptionalConverter::transform(CAttributeValuePtr& pValue)
{
    if (pValue->asString() != c_sEmptyFlag)
        CConverter::transform(pValue);
}

void COptionalConverter::doTransform(CAttributeValuePtr& pValue)
{
    // do nothing
}

void CArrayToOneConverter::transform(CAttributeValuePtr& pValue)
{
    if (pValue->getCount() > 0 && pValue->getItems(0)->asString() != c_sEmptyFlag)
    {
        pValue = pValue->getItems(0);
        CConverter::transform(pValue);
    }
    //auto str = dropDot(sValue);
    //auto nPos = str.find(L',');
    //if (nPos == std::wstring::npos)
    //{
    //    sValue = c_sEmptyFlag;
    //}
    //else
    //{
    //    sValue = str.substr(0, nPos);
    //    if (sValue != c_sEmptyFlag)
    //        CConverter::transform(sValue);
    //}
}

void CArrayToOneConverter::doTransform(CAttributeValuePtr& pValue)
{
    // do nothing
}

void COneToArrayConverter::transform(CAttributeValuePtr& pValue)
{
    CAttributeValuePtr pArrayValue(new CCompositeAttributeValue);
    if (pValue->asString() != c_sEmptyFlag)
    {
        CConverter::transform(pValue);
        pArrayValue->add(pValue);
    }
    pValue = pArrayValue;
}

void COneToArrayConverter::doTransform(CAttributeValuePtr& pValue)
{
    //auto sValue = pValue->asString();
    //if (sValue != c_sEmptyFlag)
    //{
    //    pValue = CAttributeValuePtr(new CCompositeAttributeValue);
    //    pValue->add(new CLeafAttributeValue(sValue));
    //}
}

int CConverter::boolToInt(const std::wstring & sValue)
{
    return sValue == L".T." ? 1 : 0;
}

GFC_NAMESPACE_END