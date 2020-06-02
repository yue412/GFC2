#include "StdAfx.h"
#include "NGfc2Helicoid.h"
NGfc2Helicoid::NGfc2Helicoid()
{
    m_pEntity = new Gfc2Helicoid;
    m_bOwner = true;
}

NGfc2Helicoid::NGfc2Helicoid(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Helicoid::setCoord(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setCoord(nValue);
}

gfc2::engine::EntityRef NGfc2Helicoid::getCoord()
{
    return ((Gfc2Helicoid*)m_pEntity)->getCoord();
}

bool NGfc2Helicoid::hasCoord()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasCoord();
}

NGfc2Coordinates3d^ NGfc2Helicoid::getCoordPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Helicoid*)m_pEntity)->getCoordPtr(), false);
}

void NGfc2Helicoid::setRadius(NGfc2Double dValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2Helicoid::getRadius()
{
    return ((Gfc2Helicoid*)m_pEntity)->getRadius();
}

bool NGfc2Helicoid::hasRadius()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasRadius();
}

void NGfc2Helicoid::setRangeV(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setRangeV(nValue);
}

gfc2::engine::EntityRef NGfc2Helicoid::getRangeV()
{
    return ((Gfc2Helicoid*)m_pEntity)->getRangeV();
}

bool NGfc2Helicoid::hasRangeV()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2Helicoid::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Helicoid*)m_pEntity)->getRangeVPtr(), false);
}

void NGfc2Helicoid::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2Helicoid::getClockSign()
{
    return ((Gfc2Helicoid*)m_pEntity)->getClockSign();
}

bool NGfc2Helicoid::hasClockSign()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasClockSign();
}

void NGfc2Helicoid::setHeightCoef(NGfc2Double dValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setHeightCoef(dValue);
}

NGfc2Double NGfc2Helicoid::getHeightCoef()
{
    return ((Gfc2Helicoid*)m_pEntity)->getHeightCoef();
}

bool NGfc2Helicoid::hasHeightCoef()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasHeightCoef();
}

void NGfc2Helicoid::setRadiusCoef(NGfc2Double dValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setRadiusCoef(dValue);
}

NGfc2Double NGfc2Helicoid::getRadiusCoef()
{
    return ((Gfc2Helicoid*)m_pEntity)->getRadiusCoef();
}

bool NGfc2Helicoid::hasRadiusCoef()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasRadiusCoef();
}

void NGfc2Helicoid::setCurve(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Helicoid*)m_pEntity)->setCurve(nValue);
}

gfc2::engine::EntityRef NGfc2Helicoid::getCurve()
{
    return ((Gfc2Helicoid*)m_pEntity)->getCurve();
}

bool NGfc2Helicoid::hasCurve()
{
    return ((Gfc2Helicoid*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2Helicoid::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Helicoid*)m_pEntity)->getCurvePtr(), false);
}

