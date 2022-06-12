#include "NGfcBillTotal.h"

using namespace gfc::classes::x3;

NGfcBillTotal::NGfcBillTotal()
{
    m_pEntity = new GfcBillTotal;
    m_bOwner = true;
}

NGfcBillTotal::NGfcBillTotal(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcBillTotal::setCode(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getCode()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getCode());
}

bool NGfcBillTotal::hasCode()
{
    return ((GfcBillTotal*)m_pEntity)->hasCode();
}

void NGfcBillTotal::setName(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getName()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getName());
}

bool NGfcBillTotal::hasName()
{
    return ((GfcBillTotal*)m_pEntity)->hasName();
}

void NGfcBillTotal::setAttr(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setAttr(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getAttr()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getAttr());
}

bool NGfcBillTotal::hasAttr()
{
    return ((GfcBillTotal*)m_pEntity)->hasAttr();
}

void NGfcBillTotal::setQuantityType(NGfcInteger nValue)
{
    ((GfcBillTotal*)m_pEntity)->setQuantityType(nValue);
}

NGfcInteger NGfcBillTotal::getQuantityType()
{
    return ((GfcBillTotal*)m_pEntity)->getQuantityType();
}

bool NGfcBillTotal::hasQuantityType()
{
    return ((GfcBillTotal*)m_pEntity)->hasQuantityType();
}

void NGfcBillTotal::setUnit(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getUnit()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getUnit());
}

bool NGfcBillTotal::hasUnit()
{
    return ((GfcBillTotal*)m_pEntity)->hasUnit();
}

void NGfcBillTotal::setQuantity(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getQuantity()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getQuantity());
}

bool NGfcBillTotal::hasQuantity()
{
    return ((GfcBillTotal*)m_pEntity)->hasQuantity();
}

void NGfcBillTotal::setMemo(NGfcString sValue)
{
    ((GfcBillTotal*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillTotal::getMemo()
{
    return marshal_as<String^>(((GfcBillTotal*)m_pEntity)->getMemo());
}

bool NGfcBillTotal::hasMemo()
{
    return ((GfcBillTotal*)m_pEntity)->hasMemo();
}

