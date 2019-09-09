#include "StdAfx.h"
#include "NGfc2Arc2d.h"
NGfc2Arc2d::NGfc2Arc2d()
{
    m_pEntity = new Gfc2Arc2d;
    m_bOwner = true;
}

NGfc2Arc2d::NGfc2Arc2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2Arc2d::setCenterPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setCenterPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2Arc2d::getCenterPt()
{
    return ((Gfc2Arc2d*)m_pEntity)->getCenterPt();
}

bool NGfc2Arc2d::hasCenterPt()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasCenterPt();
}

NGfc2Vector2d^ NGfc2Arc2d::getCenterPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Arc2d*)m_pEntity)->getCenterPtPtr(), false);
}

void NGfc2Arc2d::setRadius(NGfc2Double dValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2Arc2d::getRadius()
{
    return ((Gfc2Arc2d*)m_pEntity)->getRadius();
}

bool NGfc2Arc2d::hasRadius()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasRadius();
}

void NGfc2Arc2d::setRange(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setRange(nValue);
}

glodon::objectbuf::EntityRef NGfc2Arc2d::getRange()
{
    return ((Gfc2Arc2d*)m_pEntity)->getRange();
}

bool NGfc2Arc2d::hasRange()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2Arc2d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2Arc2d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2Arc2d::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2Arc2d::getClockSign()
{
    return ((Gfc2Arc2d*)m_pEntity)->getClockSign();
}

bool NGfc2Arc2d::hasClockSign()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasClockSign();
}

