#include "StdAfx.h"
#include "NGfc2Floor.h"
NGfc2Floor::NGfc2Floor()
{
    m_pEntity = new Gfc2Floor;
    m_bOwner = true;
}

NGfc2Floor::NGfc2Floor(void* pEntity, bool bOwner):
    NGfc2SpatialStructureElement(pEntity, bOwner)
{
}

void NGfc2Floor::setHeight(NGfc2Double dValue)
{
    ((Gfc2Floor*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2Floor::getHeight()
{
    return ((Gfc2Floor*)m_pEntity)->getHeight();
}

bool NGfc2Floor::hasHeight()
{
    return ((Gfc2Floor*)m_pEntity)->hasHeight();
}

void NGfc2Floor::setStdFloorCount(NGfc2Integer nValue)
{
    ((Gfc2Floor*)m_pEntity)->setStdFloorCount(nValue);
}

NGfc2Integer NGfc2Floor::getStdFloorCount()
{
    return ((Gfc2Floor*)m_pEntity)->getStdFloorCount();
}

bool NGfc2Floor::hasStdFloorCount()
{
    return ((Gfc2Floor*)m_pEntity)->hasStdFloorCount();
}

void NGfc2Floor::setStructuralElevation(NGfc2Double dValue)
{
    ((Gfc2Floor*)m_pEntity)->setStructuralElevation(dValue);
}

NGfc2Double NGfc2Floor::getStructuralElevation()
{
    return ((Gfc2Floor*)m_pEntity)->getStructuralElevation();
}

bool NGfc2Floor::hasStructuralElevation()
{
    return ((Gfc2Floor*)m_pEntity)->hasStructuralElevation();
}

void NGfc2Floor::setStartFloorNo(NGfc2Integer nValue)
{
    ((Gfc2Floor*)m_pEntity)->setStartFloorNo(nValue);
}

NGfc2Integer NGfc2Floor::getStartFloorNo()
{
    return ((Gfc2Floor*)m_pEntity)->getStartFloorNo();
}

bool NGfc2Floor::hasStartFloorNo()
{
    return ((Gfc2Floor*)m_pEntity)->hasStartFloorNo();
}

void NGfc2Floor::setRemark(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Floor*)m_pEntity)->setRemark(nValue);
}

glodon::objectbuf::EntityRef NGfc2Floor::getRemark()
{
    return ((Gfc2Floor*)m_pEntity)->getRemark();
}

bool NGfc2Floor::hasRemark()
{
    return ((Gfc2Floor*)m_pEntity)->hasRemark();
}

NGfc2Text^ NGfc2Floor::getRemarkPtr()
{
    return gcnew NGfc2Text(((Gfc2Floor*)m_pEntity)->getRemarkPtr(), false);
}

