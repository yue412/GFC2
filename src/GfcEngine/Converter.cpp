#include "Converter.h"
#include "GfcSchema\EnumType.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Property.h"

GFCENGINE_NAMESPACE_BEGIN

CConverter::~CConverter()
{
    delete m_pNext;
}

void CConverter::transform(CPropValue* pFrom, CPropValue* pTo)
{
    // Ϊ�ղ���ת��
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

void CEmptyConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    //pValue->setAsString(c_sEmptyFlag);
}

void CBoolToStringConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    //auto sValue = pValue->asString();
    //sValue = std::to_wstring(boolToInt(sValue));
    //sValue = enclosedInQuotes(sValue);
    pTo->setAsString(std::to_string(pFrom->asInteger()));
}

void CStringConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    pTo->setAsString(pFrom->asString());
}

void CIntToEnumConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    auto pEnum = dynamic_cast<gfc::schema::CEnumType*>(m_pTo);
    if (pEnum && pEnum->getEnumCount() > 0)
        pTo->setAsInteger(abs(pFrom->asInteger()) % pEnum->getEnumCount());
}

void CArrayToArrayConverter::transform(CPropValue* pFrom, CPropValue* pTo)
{
    for (int i = 0; i < pFrom->getCount(); i++)
    {
        auto pItem = pFrom->getItems(i);
        auto pToItem = CProperty::createValue(m_pTo);
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

void CArrayToArrayConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    //do nothing
}

void COptionalConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    // do nothing
}

void CArrayToOneConverter::transform(CPropValue* pFrom, CPropValue* pTo)
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

void CArrayToOneConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
{
    // do nothing
}

void COneToArrayConverter::transform(CPropValue* pFrom, CPropValue* pTo)
{
    if (!pFrom->isNull())
    {
        auto pToItem = CProperty::createValue(m_pTo);
        CConverter::transform(pFrom, pToItem);
        if (!pToItem->isNull())
            pTo->add(pToItem);
        else
            delete pToItem;
    }
}

void COneToArrayConverter::doTransform(CPropValue* pFrom, CPropValue* pTo)
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


void CIntToStringConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsString(std::to_string(pFrom->asInteger()));
}

void CIntConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsInteger(pFrom->asInteger());
}

void CFloatToStringConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsString(std::to_string(pFrom->asDouble()));
}


void CFloatConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsDouble(pFrom->asDouble());
}

void CEntityRefConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
{
    pTo->setAsEntityRef(pFrom->asEntityRef());
}

void CEnumConverter::doTransform(CPropValue * pFrom, CPropValue * pTo)
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