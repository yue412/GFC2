#include "StdAfx.h"
#include "NGfc2BillTotal.h"
NGfc2BillTotal::NGfc2BillTotal()
{
    m_pEntity = new Gfc2BillTotal;
    m_bOwner = true;
}

NGfc2BillTotal::NGfc2BillTotal(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2BillTotal::setCode(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setCode(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getCode()
{
    return ((Gfc2BillTotal*)m_pEntity)->getCode();
}

bool NGfc2BillTotal::hasCode()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasCode();
}

NGfc2String^ NGfc2BillTotal::getCodePtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getCodePtr(), false);
}

void NGfc2BillTotal::setName(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setName(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getName()
{
    return ((Gfc2BillTotal*)m_pEntity)->getName();
}

bool NGfc2BillTotal::hasName()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasName();
}

NGfc2String^ NGfc2BillTotal::getNamePtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getNamePtr(), false);
}

void NGfc2BillTotal::setAttr(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setAttr(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getAttr()
{
    return ((Gfc2BillTotal*)m_pEntity)->getAttr();
}

bool NGfc2BillTotal::hasAttr()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasAttr();
}

NGfc2String^ NGfc2BillTotal::getAttrPtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getAttrPtr(), false);
}

void NGfc2BillTotal::setQuantityType(NGfc2Integer nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setQuantityType(nValue);
}

NGfc2Integer NGfc2BillTotal::getQuantityType()
{
    return ((Gfc2BillTotal*)m_pEntity)->getQuantityType();
}

bool NGfc2BillTotal::hasQuantityType()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasQuantityType();
}

void NGfc2BillTotal::setUnit(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setUnit(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getUnit()
{
    return ((Gfc2BillTotal*)m_pEntity)->getUnit();
}

bool NGfc2BillTotal::hasUnit()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasUnit();
}

NGfc2String^ NGfc2BillTotal::getUnitPtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getUnitPtr(), false);
}

void NGfc2BillTotal::setQuantity(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setQuantity(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getQuantity()
{
    return ((Gfc2BillTotal*)m_pEntity)->getQuantity();
}

bool NGfc2BillTotal::hasQuantity()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasQuantity();
}

NGfc2String^ NGfc2BillTotal::getQuantityPtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getQuantityPtr(), false);
}

void NGfc2BillTotal::setMemo(gfc::engine::EntityRef nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setMemo(nValue);
}

gfc::engine::EntityRef NGfc2BillTotal::getMemo()
{
    return ((Gfc2BillTotal*)m_pEntity)->getMemo();
}

bool NGfc2BillTotal::hasMemo()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasMemo();
}

NGfc2String^ NGfc2BillTotal::getMemoPtr()
{
    return gcnew NGfc2String(((Gfc2BillTotal*)m_pEntity)->getMemoPtr(), false);
}

