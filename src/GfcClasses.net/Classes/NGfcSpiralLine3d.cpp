#include "NGfcSpiralLine3d.h"

using namespace gfc::classes::x3;

NGfcSpiralLine3d::NGfcSpiralLine3d()
{
    m_pEntity = new GfcSpiralLine3d;
    m_bOwner = true;
}

NGfcSpiralLine3d::NGfcSpiralLine3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve3d(pEntity, bOwner)
{
}

void NGfcSpiralLine3d::setCoord(gfc::engine::EntityRef nValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfcSpiralLine3d::getCoord()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getCoord();
}

bool NGfcSpiralLine3d::hasCoord()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasCoord();
}

void NGfcSpiralLine3d::setRadius(NGfcDouble dValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcSpiralLine3d::getRadius()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getRadius();
}

bool NGfcSpiralLine3d::hasRadius()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasRadius();
}

void NGfcSpiralLine3d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcSpiralLine3d::getRange()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getRange();
}

bool NGfcSpiralLine3d::hasRange()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasRange();
}

void NGfcSpiralLine3d::setClockSign(NGfcInteger nValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcSpiralLine3d::getClockSign()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getClockSign();
}

bool NGfcSpiralLine3d::hasClockSign()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasClockSign();
}

void NGfcSpiralLine3d::setHeightCoef(NGfcDouble dValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setHeightCoef(dValue);
}

NGfcDouble NGfcSpiralLine3d::getHeightCoef()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getHeightCoef();
}

bool NGfcSpiralLine3d::hasHeightCoef()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasHeightCoef();
}

void NGfcSpiralLine3d::setRadiusCoef(NGfcDouble dValue)
{
    ((GfcSpiralLine3d*)m_pEntity)->setRadiusCoef(dValue);
}

NGfcDouble NGfcSpiralLine3d::getRadiusCoef()
{
    return ((GfcSpiralLine3d*)m_pEntity)->getRadiusCoef();
}

bool NGfcSpiralLine3d::hasRadiusCoef()
{
    return ((GfcSpiralLine3d*)m_pEntity)->hasRadiusCoef();
}

