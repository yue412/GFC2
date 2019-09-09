#include "StdAfx.h"
#include "NGfc2QuotaDetail.h"
NGfc2QuotaDetail::NGfc2QuotaDetail()
{
    m_pEntity = new Gfc2QuotaDetail;
    m_bOwner = true;
}

NGfc2QuotaDetail::NGfc2QuotaDetail(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2QuotaDetail::setFloorNum(NGfc2Integer nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfc2Integer NGfc2QuotaDetail::getFloorNum()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getFloorNum();
}

bool NGfc2QuotaDetail::hasFloorNum()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasFloorNum();
}

void NGfc2QuotaDetail::setEntityID(NGfc2Integer nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setEntityID(nValue);
}

NGfc2Integer NGfc2QuotaDetail::getEntityID()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getEntityID();
}

bool NGfc2QuotaDetail::hasEntityID()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasEntityID();
}

void NGfc2QuotaDetail::setUnit(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setUnit(nValue);
}

glodon::objectbuf::EntityRef NGfc2QuotaDetail::getUnit()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getUnit();
}

bool NGfc2QuotaDetail::hasUnit()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasUnit();
}

NGfc2String^ NGfc2QuotaDetail::getUnitPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaDetail*)m_pEntity)->getUnitPtr(), false);
}

void NGfc2QuotaDetail::setExpress(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setExpress(nValue);
}

glodon::objectbuf::EntityRef NGfc2QuotaDetail::getExpress()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getExpress();
}

bool NGfc2QuotaDetail::hasExpress()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasExpress();
}

NGfc2String^ NGfc2QuotaDetail::getExpressPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaDetail*)m_pEntity)->getExpressPtr(), false);
}

void NGfc2QuotaDetail::setQuantity(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setQuantity(nValue);
}

glodon::objectbuf::EntityRef NGfc2QuotaDetail::getQuantity()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getQuantity();
}

bool NGfc2QuotaDetail::hasQuantity()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasQuantity();
}

NGfc2String^ NGfc2QuotaDetail::getQuantityPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaDetail*)m_pEntity)->getQuantityPtr(), false);
}

void NGfc2QuotaDetail::setMemo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setMemo(nValue);
}

glodon::objectbuf::EntityRef NGfc2QuotaDetail::getMemo()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getMemo();
}

bool NGfc2QuotaDetail::hasMemo()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasMemo();
}

NGfc2String^ NGfc2QuotaDetail::getMemoPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaDetail*)m_pEntity)->getMemoPtr(), false);
}

