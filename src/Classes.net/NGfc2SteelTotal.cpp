#include "StdAfx.h"
#include "NGfc2SteelTotal.h"
NGfc2SteelTotal::NGfc2SteelTotal()
{
    m_pEntity = new Gfc2SteelTotal;
    m_bOwner = true;
}

NGfc2SteelTotal::NGfc2SteelTotal(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2SteelTotal::setCompType(NGfc2String sValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setCompType(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2SteelTotal::getCompType()
{
    return marshal_as<String^>(((Gfc2SteelTotal*)m_pEntity)->getCompType());
}

bool NGfc2SteelTotal::hasCompType()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasCompType();
}

void NGfc2SteelTotal::setLevel(NGfc2String sValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setLevel(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2SteelTotal::getLevel()
{
    return marshal_as<String^>(((Gfc2SteelTotal*)m_pEntity)->getLevel());
}

bool NGfc2SteelTotal::hasLevel()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasLevel();
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

void NGfc2SteelTotal::setUnit(NGfc2String sValue)
{
    ((Gfc2SteelTotal*)m_pEntity)->setUnit(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2SteelTotal::getUnit()
{
    return marshal_as<String^>(((Gfc2SteelTotal*)m_pEntity)->getUnit());
}

bool NGfc2SteelTotal::hasUnit()
{
    return ((Gfc2SteelTotal*)m_pEntity)->hasUnit();
}

