#include "StdAfx.h"
#include "NGfc2SpiralLine3d.h"
NGfc2SpiralLine3d::NGfc2SpiralLine3d()
{
    m_pEntity = new Gfc2SpiralLine3d;
    m_bOwner = true;
}

NGfc2SpiralLine3d::NGfc2SpiralLine3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2SpiralLine3d::setCoord(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setCoord(nValue);
}

gfc2::engine::EntityRef NGfc2SpiralLine3d::getCoord()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getCoord();
}

bool NGfc2SpiralLine3d::hasCoord()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasCoord();
}

NGfc2Coordinates3d^ NGfc2SpiralLine3d::getCoordPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2SpiralLine3d*)m_pEntity)->getCoordPtr(), false);
}

void NGfc2SpiralLine3d::setRadius(NGfc2Double dValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2SpiralLine3d::getRadius()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getRadius();
}

bool NGfc2SpiralLine3d::hasRadius()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasRadius();
}

void NGfc2SpiralLine3d::setRange(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setRange(nValue);
}

gfc2::engine::EntityRef NGfc2SpiralLine3d::getRange()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getRange();
}

bool NGfc2SpiralLine3d::hasRange()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2SpiralLine3d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2SpiralLine3d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2SpiralLine3d::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2SpiralLine3d::getClockSign()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getClockSign();
}

bool NGfc2SpiralLine3d::hasClockSign()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasClockSign();
}

void NGfc2SpiralLine3d::setHeightCoef(NGfc2Double dValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setHeightCoef(dValue);
}

NGfc2Double NGfc2SpiralLine3d::getHeightCoef()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getHeightCoef();
}

bool NGfc2SpiralLine3d::hasHeightCoef()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasHeightCoef();
}

void NGfc2SpiralLine3d::setRadiusCoef(NGfc2Double dValue)
{
    ((Gfc2SpiralLine3d*)m_pEntity)->setRadiusCoef(dValue);
}

NGfc2Double NGfc2SpiralLine3d::getRadiusCoef()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->getRadiusCoef();
}

bool NGfc2SpiralLine3d::hasRadiusCoef()
{
    return ((Gfc2SpiralLine3d*)m_pEntity)->hasRadiusCoef();
}

