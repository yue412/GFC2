#include "NGfc2SpiralLine2d.h"

using namespace gfc::classes::x3;

NGfc2SpiralLine2d::NGfc2SpiralLine2d()
{
    m_pEntity = new Gfc2SpiralLine2d;
    m_bOwner = true;
}

NGfc2SpiralLine2d::NGfc2SpiralLine2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2SpiralLine2d::setCoord(gfc::engine::EntityRef nValue)
{
    ((Gfc2SpiralLine2d*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfc2SpiralLine2d::getCoord()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->getCoord();
}

bool NGfc2SpiralLine2d::hasCoord()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->hasCoord();
}

void NGfc2SpiralLine2d::setRadius(NGfc2Double dValue)
{
    ((Gfc2SpiralLine2d*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2SpiralLine2d::getRadius()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->getRadius();
}

bool NGfc2SpiralLine2d::hasRadius()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->hasRadius();
}

void NGfc2SpiralLine2d::setRange(gfc::engine::EntityRef nValue)
{
    ((Gfc2SpiralLine2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfc2SpiralLine2d::getRange()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->getRange();
}

bool NGfc2SpiralLine2d::hasRange()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->hasRange();
}

void NGfc2SpiralLine2d::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2SpiralLine2d*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2SpiralLine2d::getClockSign()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->getClockSign();
}

bool NGfc2SpiralLine2d::hasClockSign()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->hasClockSign();
}

void NGfc2SpiralLine2d::setRadiusCoef(NGfc2Double dValue)
{
    ((Gfc2SpiralLine2d*)m_pEntity)->setRadiusCoef(dValue);
}

NGfc2Double NGfc2SpiralLine2d::getRadiusCoef()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->getRadiusCoef();
}

bool NGfc2SpiralLine2d::hasRadiusCoef()
{
    return ((Gfc2SpiralLine2d*)m_pEntity)->hasRadiusCoef();
}

