#include "Converter.h"
#include "EnumType.h"

GFC_NAMESPACE_BEGIN

const wchar_t* c_sEmptyFlag = L"$";

CConverter::~CConverter()
{
    delete m_pNext;
}

void CConverter::transform(std::wstring & sValue)
{
    if (m_pNext)
        m_pNext->transform(sValue);
    doTransform(sValue);
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
    return pEnum && pEnum->getEnumCount() > nIndex && nIndex >= 0 ? enclosedInDot(pEnum->getEnum(nIndex)) : c_sEmptyFlag;
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

void CCopyConverter::doTransform(std::wstring & sValue)
{
    // do nothing
}
void CEnumConverter::doTransform(std::wstring & sValue)
{
    auto pEnum = dynamic_cast<CEnumType*>(m_pTo);
    if (!pEnum || !pEnum->exists(dropDot(sValue)))
    {
        sValue = c_sEmptyFlag;
    }
}

void CEmptyConverter::doTransform(std::wstring & sValue)
{
    sValue = c_sEmptyFlag;
}

void CBoolToIntConverter::doTransform(std::wstring & sValue)
{
    sValue = std::to_wstring(boolToInt(sValue));
}

void CBoolToStringConverter::doTransform(std::wstring & sValue)
{
    sValue = std::to_wstring(boolToInt(sValue));
    sValue = enclosedInQuotes(sValue);
}

void CBoolToEnumConverter::doTransform(std::wstring & sValue)
{
    auto nIndex = boolToInt(sValue);
    sValue = intToEnum(nIndex);
}

void CIntToBoolConverter::doTransform(std::wstring & sValue)
{
    auto nValue = std::stoi(sValue);
    sValue = intToBool(nValue);
}

void CStringConverter::doTransform(std::wstring & sValue)
{
    sValue = enclosedInQuotes(sValue);
}

void CIntToEnumConverter::doTransform(std::wstring & sValue)
{
    auto nIndex = std::stoi(sValue);
    sValue = intToEnum(nIndex);
}

void CEnumToBoolConverter::doTransform(std::wstring & sValue)
{
    auto nIndex = enumToInt(sValue);
    sValue = nIndex == -1 ? c_sEmptyFlag : intToBool(nIndex);
}

void CEnumToIntConverter::doTransform(std::wstring & sValue)
{
    auto nIndex = enumToInt(sValue);
    sValue = nIndex == -1 ? c_sEmptyFlag : std::to_wstring(nIndex);
}

void CEnumToStringConverter::doTransform(std::wstring & sValue)
{
    auto nIndex = enumToInt(sValue);
    sValue = nIndex == -1 ? c_sEmptyFlag : enclosedInQuotes(std::to_wstring(nIndex));
}

void CArrayToArrayConverter::transform(std::wstring & sValue)
{
    if (sValue != c_sEmptyFlag && sValue != L"()")
    {
        std::wstring sResult;
        auto str = dropDot(sValue) + L",";
        std::size_t nStart = 0;
        auto nPos = str.find(L',');
        while (nPos != std::wstring::npos)
        {
            auto sVal = str.substr(0, nPos);
            if (sVal != c_sEmptyFlag)
                CConverter::transform(sVal);
            sResult += sVal + L",";
            nStart = nPos + 1;
            nPos = str.find(L',', nStart);
        }
        sValue = enclosedInBrackets(sResult.substr(0, sResult.length() - 1));
    }
}

void CArrayToArrayConverter::doTransform(std::wstring & sValue)
{
    //do nothing
}

void COptionalConverter::transform(std::wstring & sValue)
{
    if (sValue != c_sEmptyFlag)
        CConverter::transform(sValue);
}

void COptionalConverter::doTransform(std::wstring & sValue)
{
    // do nothing
}

void CArrayToOneConverter::transform(std::wstring & sValue)
{
    auto str = dropDot(sValue);
    auto nPos = str.find(L',');
    if (nPos == std::wstring::npos)
    {
        sValue = c_sEmptyFlag;
    }
    else
    {
        sValue = str.substr(0, nPos);
        if (sValue != c_sEmptyFlag)
            CConverter::transform(sValue);
    }
}

void CArrayToOneConverter::doTransform(std::wstring & sValue)
{
    // do nothing
}

void COneToArrayConverter::transform(std::wstring & sValue)
{
    if (sValue != c_sEmptyFlag)
        CConverter::transform(sValue);
}

void COneToArrayConverter::doTransform(std::wstring & sValue)
{
    if (sValue != c_sEmptyFlag)
        sValue = enclosedInBrackets(sValue);
}

int CConverter::boolToInt(const std::wstring & sValue)
{
    return sValue == L".T." ? 1 : 0;
}

GFC_NAMESPACE_END