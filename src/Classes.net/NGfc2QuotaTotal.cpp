#include "StdAfx.h"
#include "NGfc2QuotaTotal.h"
NGfc2QuotaTotal::NGfc2QuotaTotal()
{
    m_pEntity = new Gfc2QuotaTotal;
    m_bOwner = true;
}

NGfc2QuotaTotal::NGfc2QuotaTotal(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2QuotaTotal::setCode(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setCode(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getCode();
}

bool NGfc2QuotaTotal::hasCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasCode();
}

NGfc2String^ NGfc2QuotaTotal::getCodePtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getCodePtr(), false);
}

void NGfc2QuotaTotal::setSubCode(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setSubCode(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getSubCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getSubCode();
}

bool NGfc2QuotaTotal::hasSubCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasSubCode();
}

NGfc2String^ NGfc2QuotaTotal::getSubCodePtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getSubCodePtr(), false);
}

void NGfc2QuotaTotal::setName(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setName(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getName()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getName();
}

bool NGfc2QuotaTotal::hasName()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasName();
}

NGfc2String^ NGfc2QuotaTotal::getNamePtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getNamePtr(), false);
}

void NGfc2QuotaTotal::setContent(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setContent(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getContent()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getContent();
}

bool NGfc2QuotaTotal::hasContent()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasContent();
}

NGfc2String^ NGfc2QuotaTotal::getContentPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getContentPtr(), false);
}

void NGfc2QuotaTotal::setUnit(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setUnit(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getUnit()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getUnit();
}

bool NGfc2QuotaTotal::hasUnit()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasUnit();
}

NGfc2String^ NGfc2QuotaTotal::getUnitPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getUnitPtr(), false);
}

void NGfc2QuotaTotal::setQuantity(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setQuantity(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getQuantity()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getQuantity();
}

bool NGfc2QuotaTotal::hasQuantity()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasQuantity();
}

NGfc2String^ NGfc2QuotaTotal::getQuantityPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getQuantityPtr(), false);
}

void NGfc2QuotaTotal::setMemo(gfc2::engine::EntityRef nValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setMemo(nValue);
}

gfc2::engine::EntityRef NGfc2QuotaTotal::getMemo()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->getMemo();
}

bool NGfc2QuotaTotal::hasMemo()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasMemo();
}

NGfc2String^ NGfc2QuotaTotal::getMemoPtr()
{
    return gcnew NGfc2String(((Gfc2QuotaTotal*)m_pEntity)->getMemoPtr(), false);
}

