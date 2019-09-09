#include "StdAfx.h"
#include "NGfc2SteelTotal.h"
NGfc2SteelTotal::NGfc2SteelTotal()
{
    m_pEntity = new Gfc2SteelTotal;
    m_bOwner = true;
}

NGfc2SteelTotal::NGfc2SteelTotal(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2SteelTotal::setCompType(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setCompType(nValue);
}

glodon::objectbuf::EntityRef NGfc2SteelTotal::getCompType()
{
    return ((Gfc2SteelTotal*)m_pEntity)->getCompType();
}

bool NGfc2SteelTotal::hasCompType()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasCompType();
}

NGfc2String^ NGfc2SteelTotal::getCompTypePtr()
{
    return gcnew NGfc2String(((Gfc2SteelTotal*)m_pEntity)->getCompTypePtr(), false);
}

void NGfc2SteelTotal::setLevel(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setLevel(nValue);
}

glodon::objectbuf::EntityRef NGfc2SteelTotal::getLevel()
{
    return ((Gfc2SteelTotal*)m_pEntity)->getLevel();
}

bool NGfc2SteelTotal::hasLevel()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasLevel();
}

NGfc2String^ NGfc2SteelTotal::getLevelPtr()
{
    return gcnew NGfc2String(((Gfc2SteelTotal*)m_pEntity)->getLevelPtr(), false);
}

void NGfc2SteelTotal::setDia(NGfc2Integer nValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setDia(nValue);
}

NGfc2Integer NGfc2SteelTotal::getDia()
{
    return ((Gfc2SteelTotal*)m_pEntity)->getDia();
}

bool NGfc2SteelTotal::hasDia()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasDia();
}

void NGfc2SteelTotal::setWeight(NGfc2Double dValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setWeight(dValue);
}

NGfc2Double NGfc2SteelTotal::getWeight()
{
    return ((Gfc2SteelTotal*)m_pEntity)->getWeight();
}

bool NGfc2SteelTotal::hasWeight()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasWeight();
}

void NGfc2SteelTotal::setUnit(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setUnit(nValue);
}

glodon::objectbuf::EntityRef NGfc2SteelTotal::getUnit()
{
    return ((Gfc2SteelTotal*)m_pEntity)->getUnit();
}

bool NGfc2SteelTotal::hasUnit()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasUnit();
}

NGfc2String^ NGfc2SteelTotal::getUnitPtr()
{
    return gcnew NGfc2String(((Gfc2SteelTotal*)m_pEntity)->getUnitPtr(), false);
}

