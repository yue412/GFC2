#include "StdAfx.h"
#include "NGfc2BillDetail.h"
NGfc2BillDetail::NGfc2BillDetail()
{
    m_pEntity = new Gfc2BillDetail;
    m_bOwner = true;
}

NGfc2BillDetail::NGfc2BillDetail(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2BillDetail::setFloorNum(NGfc2Integer nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfc2Integer NGfc2BillDetail::getFloorNum()
{
    return ((Gfc2BillDetail*)m_pEntity)->getFloorNum();
}

bool NGfc2BillDetail::hasFloorNum()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasFloorNum();
}

void NGfc2BillDetail::setEntityID(NGfc2Integer nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setEntityID(nValue);
}

NGfc2Integer NGfc2BillDetail::getEntityID()
{
    return ((Gfc2BillDetail*)m_pEntity)->getEntityID();
}

bool NGfc2BillDetail::hasEntityID()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasEntityID();
}

void NGfc2BillDetail::setUnit(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setUnit(nValue);
}

glodon::objectbuf::EntityRef NGfc2BillDetail::getUnit()
{
    return ((Gfc2BillDetail*)m_pEntity)->getUnit();
}

bool NGfc2BillDetail::hasUnit()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasUnit();
}

NGfc2String^ NGfc2BillDetail::getUnitPtr()
{
    return gcnew NGfc2String(((Gfc2BillDetail*)m_pEntity)->getUnitPtr(), false);
}

void NGfc2BillDetail::setExpress(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setExpress(nValue);
}

glodon::objectbuf::EntityRef NGfc2BillDetail::getExpress()
{
    return ((Gfc2BillDetail*)m_pEntity)->getExpress();
}

bool NGfc2BillDetail::hasExpress()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasExpress();
}

NGfc2String^ NGfc2BillDetail::getExpressPtr()
{
    return gcnew NGfc2String(((Gfc2BillDetail*)m_pEntity)->getExpressPtr(), false);
}

void NGfc2BillDetail::setQuantity(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setQuantity(nValue);
}

glodon::objectbuf::EntityRef NGfc2BillDetail::getQuantity()
{
    return ((Gfc2BillDetail*)m_pEntity)->getQuantity();
}

bool NGfc2BillDetail::hasQuantity()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasQuantity();
}

NGfc2String^ NGfc2BillDetail::getQuantityPtr()
{
    return gcnew NGfc2String(((Gfc2BillDetail*)m_pEntity)->getQuantityPtr(), false);
}

void NGfc2BillDetail::setMemo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setMemo(nValue);
}

glodon::objectbuf::EntityRef NGfc2BillDetail::getMemo()
{
    return ((Gfc2BillDetail*)m_pEntity)->getMemo();
}

bool NGfc2BillDetail::hasMemo()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasMemo();
}

NGfc2String^ NGfc2BillDetail::getMemoPtr()
{
    return gcnew NGfc2String(((Gfc2BillDetail*)m_pEntity)->getMemoPtr(), false);
}

