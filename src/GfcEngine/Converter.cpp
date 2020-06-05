#include "Converter.h"
#include "GfcSchema\EnumType.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Property.h"

GFCENGINE_NAMESPACE_BEGIN

CConverter::~CConverter()
{
    delete m_pNext;
}

void CConverter::transform(PropValue* pFrom, PropValue* pTo)
{
    // 为空不用转换
    if (pFrom->isNull())
        return;
    if (m_pNext)
        m_pNext->transform(pFrom, pTo);
    doTransform(pFrom, pTo);
}

void CConverter::setNext(CConverter * pNext)
{
    delete m_pNext;
    m_pNext = pNext;
}

void CConverter::init(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    m_pFrom = pFrom;
    m_pTo = pTo;
    if (m_pNext)
        m_pNext->init(pFrom, pTo);
}

void CEmptyConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    //pValue->setAsString(c_sEmptyFlag);
}

void CBoolToStringConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    //auto sValue = pValue->asString();
    //sValue = std::to_wstring(boolToInt(sValue));
    //sValue = enclosedInQuotes(sValue);
    pTo->setAsString(std::to_string(pFrom->asInteger()));
}

void CStringConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    pTo->setAsString(pFrom->asString());
}

void CIntToEnumConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    auto pEnum = dynamic_cast<gfc::schema::CEnumType*>(m_pTo);
    if (pEnum && pEnum->getEnumCount() > 0)
        pTo->setAsInteger(abs(pFrom->asInteger()) % pEnum->getEnumCount());
}

void CArrayToArrayConverter::transform(PropValue* pFrom, PropValue* pTo)
{
    for (int i = 0; i < pFrom->getCount(); i++)
    {
        auto pItem = pFrom->getItems(i);
        auto pToItem = Property::createValue(m_pTo);
        CConverter::transform(pItem, pToItem);
        if (!pToItem->isNull())
            pTo->add(pToItem);
        else
            delete pToItem;
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

void CArrayToArrayConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    //do nothing
}

void COptionalConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    // do nothing
}

void CArrayToOneConverter::transform(PropValue* pFrom, PropValue* pTo)
{
    if (pFrom->getCount() > 0 && !pFrom->getItems(0)->isNull())
    {
        auto pItem = pFrom->getItems(0);
        CConverter::transform(pItem, pTo);
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

void CArrayToOneConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    // do nothing
}

void COneToArrayConverter::transform(PropValue* pFrom, PropValue* pTo)
{
    if (!pFrom->isNull())
    {
        auto pToItem = Property::createValue(m_pTo);
        CConverter::transform(pFrom, pToItem);
        if (!pToItem->isNull())
            pTo->add(pToItem);
        else
            delete pToItem;
    }
}

void COneToArrayConverter::doTransform(PropValue* pFrom, PropValue* pTo)
{
    //auto sValue = pValue->asString();
    //if (sValue != c_sEmptyFlag)
    //{
    //    pValue = CAttributeValuePtr(new CCompositeAttributeValue);
    //    pValue->add(new CLeafAttributeValue(sValue));
    //}
}

//int CConverter::boolToInt(const std::wstring & sValue)
//{
//    return sValue == L".T." ? 1 : 0;
//}


void CIntToStringConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    pTo->setAsString(std::to_string(pFrom->asInteger()));
}

void CIntConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    pTo->setAsInteger(pFrom->asInteger());
}

void CFloatToStringConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    pTo->setAsString(std::to_string(pFrom->asDouble()));
}


void CFloatConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    pTo->setAsDouble(pFrom->asDouble());
}

void CEntityRefConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    pTo->setAsEntityRef(pFrom->asEntityRef());
}

void CEnumConverter::doTransform(PropValue * pFrom, PropValue * pTo)
{
    auto pToEnum = dynamic_cast<gfc::schema::CEnumType*>(m_pTo);
    auto pFromEnum = dynamic_cast<gfc::schema::CEnumType*>(m_pFrom);
    //pFromEnum->getEnum()
    if (pFromEnum && pFrom->asInteger() < pFromEnum->getEnumCount())
    {
        auto sEnum = pFromEnum->getEnum(pFrom->asInteger());
        if (pToEnum)
        {
            auto nIndex = pToEnum->indexOf(sEnum);
            if (nIndex >= 0)
            {
                pTo->setAsInteger(nIndex);
            }
        }
    }
}

GFCENGINE_NAMESPACE_END