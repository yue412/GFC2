#include "NGfcQuotaTotal.h"

using namespace gfc::classes::x3;

NGfcQuotaTotal::NGfcQuotaTotal()
{
    m_pEntity = new GfcQuotaTotal;
    m_bOwner = true;
}

NGfcQuotaTotal::NGfcQuotaTotal(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcQuotaTotal::setCode(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getCode()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getCode());
}

bool NGfcQuotaTotal::hasCode()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasCode();
}

void NGfcQuotaTotal::setSubCode(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setSubCode(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getSubCode()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getSubCode());
}

bool NGfcQuotaTotal::hasSubCode()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasSubCode();
}

void NGfcQuotaTotal::setName(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getName()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getName());
}

bool NGfcQuotaTotal::hasName()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasName();
}

void NGfcQuotaTotal::setContent(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setContent(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getContent()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getContent());
}

bool NGfcQuotaTotal::hasContent()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasContent();
}

void NGfcQuotaTotal::setUnit(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getUnit()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getUnit());
}

bool NGfcQuotaTotal::hasUnit()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasUnit();
}

void NGfcQuotaTotal::setQuantity(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getQuantity()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getQuantity());
}

bool NGfcQuotaTotal::hasQuantity()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasQuantity();
}

void NGfcQuotaTotal::setMemo(NGfcString sValue)
{
    ((GfcQuotaTotal*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaTotal::getMemo()
{
    return marshal_as<String^>(((GfcQuotaTotal*)m_pEntity)->getMemo());
}

bool NGfcQuotaTotal::hasMemo()
{
    return ((GfcQuotaTotal*)m_pEntity)->hasMemo();
}

