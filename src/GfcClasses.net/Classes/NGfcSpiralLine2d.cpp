#include "NGfcSpiralLine2d.h"

using namespace gfc::classes::x3;

NGfcSpiralLine2d::NGfcSpiralLine2d()
{
    m_pEntity = new GfcSpiralLine2d;
    m_bOwner = true;
}

NGfcSpiralLine2d::NGfcSpiralLine2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve2d(pEntity, bOwner)
{
}

void NGfcSpiralLine2d::setCoord(gfc::engine::EntityRef nValue)
{
    ((GfcSpiralLine2d*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfcSpiralLine2d::getCoord()
{
    return ((GfcSpiralLine2d*)m_pEntity)->getCoord();
}

bool NGfcSpiralLine2d::hasCoord()
{
    return ((GfcSpiralLine2d*)m_pEntity)->hasCoord();
}

void NGfcSpiralLine2d::setRadius(NGfcDouble dValue)
{
    ((GfcSpiralLine2d*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcSpiralLine2d::getRadius()
{
    return ((GfcSpiralLine2d*)m_pEntity)->getRadius();
}

bool NGfcSpiralLine2d::hasRadius()
{
    return ((GfcSpiralLine2d*)m_pEntity)->hasRadius();
}

void NGfcSpiralLine2d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcSpiralLine2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcSpiralLine2d::getRange()
{
    return ((GfcSpiralLine2d*)m_pEntity)->getRange();
}

bool NGfcSpiralLine2d::hasRange()
{
    return ((GfcSpiralLine2d*)m_pEntity)->hasRange();
}

void NGfcSpiralLine2d::setClockSign(NGfcInteger nValue)
{
    ((GfcSpiralLine2d*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcSpiralLine2d::getClockSign()
{
    return ((GfcSpiralLine2d*)m_pEntity)->getClockSign();
}

bool NGfcSpiralLine2d::hasClockSign()
{
    return ((GfcSpiralLine2d*)m_pEntity)->hasClockSign();
}

void NGfcSpiralLine2d::setRadiusCoef(NGfcDouble dValue)
{
    ((GfcSpiralLine2d*)m_pEntity)->setRadiusCoef(dValue);
}

NGfcDouble NGfcSpiralLine2d::getRadiusCoef()
{
    return ((GfcSpiralLine2d*)m_pEntity)->getRadiusCoef();
}

bool NGfcSpiralLine2d::hasRadiusCoef()
{
    return ((GfcSpiralLine2d*)m_pEntity)->hasRadiusCoef();
}

