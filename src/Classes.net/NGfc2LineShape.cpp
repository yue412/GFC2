#include "StdAfx.h"
#include "NGfc2LineShape.h"
NGfc2LineShape::NGfc2LineShape()
{
    m_pEntity = new Gfc2LineShape;
    m_bOwner = true;
}

NGfc2LineShape::NGfc2LineShape(void* pEntity, bool bOwner):
    NGfc2CustomLineShape(pEntity, bOwner)
{
}

void NGfc2LineShape::setTilt(NGfc2Double dValue)
{
    ((Gfc2LineShape*)m_pEntity)->setTilt(dValue);
}

NGfc2Double NGfc2LineShape::getTilt()
{
    return ((Gfc2LineShape*)m_pEntity)->getTilt();
}

bool NGfc2LineShape::hasTilt()
{
    return ((Gfc2LineShape*)m_pEntity)->hasTilt();
}

void NGfc2LineShape::setStartPtHeight(NGfc2Double dValue)
{
    ((Gfc2LineShape*)m_pEntity)->setStartPtHeight(dValue);
}

NGfc2Double NGfc2LineShape::getStartPtHeight()
{
    return ((Gfc2LineShape*)m_pEntity)->getStartPtHeight();
}

bool NGfc2LineShape::hasStartPtHeight()
{
    return ((Gfc2LineShape*)m_pEntity)->hasStartPtHeight();
}

void NGfc2LineShape::setEndPtHeight(NGfc2Double dValue)
{
    ((Gfc2LineShape*)m_pEntity)->setEndPtHeight(dValue);
}

NGfc2Double NGfc2LineShape::getEndPtHeight()
{
    return ((Gfc2LineShape*)m_pEntity)->getEndPtHeight();
}

bool NGfc2LineShape::hasEndPtHeight()
{
    return ((Gfc2LineShape*)m_pEntity)->hasEndPtHeight();
}

void NGfc2LineShape::setArcInfo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2LineShape*)m_pEntity)->setArcInfo(nValue);
}

glodon::objectbuf::EntityRef NGfc2LineShape::getArcInfo()
{
    return ((Gfc2LineShape*)m_pEntity)->getArcInfo();
}

bool NGfc2LineShape::hasArcInfo()
{
    return ((Gfc2LineShape*)m_pEntity)->hasArcInfo();
}

NGfc2LineArcInfo^ NGfc2LineShape::getArcInfoPtr()
{
    return gcnew NGfc2LineArcInfo(((Gfc2LineShape*)m_pEntity)->getArcInfoPtr(), false);
}

void NGfc2LineShape::setIsSpiralTop(NGfc2Boolean bValue)
{
    ((Gfc2LineShape*)m_pEntity)->setIsSpiralTop(bValue);
}

NGfc2Boolean NGfc2LineShape::getIsSpiralTop()
{
    return ((Gfc2LineShape*)m_pEntity)->getIsSpiralTop();
}

bool NGfc2LineShape::hasIsSpiralTop()
{
    return ((Gfc2LineShape*)m_pEntity)->hasIsSpiralTop();
}

void NGfc2LineShape::setIsSpiralBtm(NGfc2Boolean bValue)
{
    ((Gfc2LineShape*)m_pEntity)->setIsSpiralBtm(bValue);
}

NGfc2Boolean NGfc2LineShape::getIsSpiralBtm()
{
    return ((Gfc2LineShape*)m_pEntity)->getIsSpiralBtm();
}

bool NGfc2LineShape::hasIsSpiralBtm()
{
    return ((Gfc2LineShape*)m_pEntity)->hasIsSpiralBtm();
}

