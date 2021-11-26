#include "NGfc2Arc2d.h"

using namespace gfc::classes::x3;

NGfc2Arc2d::NGfc2Arc2d()
{
    m_pEntity = new Gfc2Arc2d;
    m_bOwner = true;
}

NGfc2Arc2d::NGfc2Arc2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2Arc2d::setCenterPt(gfc::engine::EntityRef nValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setCenterPt(nValue);
}

gfc::engine::EntityRef NGfc2Arc2d::getCenterPt()
{
    return ((Gfc2Arc2d*)m_pEntity)->getCenterPt();
}

bool NGfc2Arc2d::hasCenterPt()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasCenterPt();
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

void NGfc2Arc2d::setRange(gfc::engine::EntityRef nValue)
{
    ((Gfc2Arc2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfc2Arc2d::getRange()
{
    return ((Gfc2Arc2d*)m_pEntity)->getRange();
}

bool NGfc2Arc2d::hasRange()
{
    return ((Gfc2Arc2d*)m_pEntity)->hasRange();
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

