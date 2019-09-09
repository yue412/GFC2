#include "StdAfx.h"
#include "NGfc2Torus.h"
NGfc2Torus::NGfc2Torus()
{
    m_pEntity = new Gfc2Torus;
    m_bOwner = true;
}

NGfc2Torus::NGfc2Torus(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Torus::setCoord(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setCoord(nValue);
}

glodon::objectbuf::EntityRef NGfc2Torus::getCoord()
{
    return ((Gfc2Torus*)m_pEntity)->getCoord();
}

bool NGfc2Torus::hasCoord()
{
    return ((Gfc2Torus*)m_pEntity)->hasCoord();
}

NGfc2Coordinates3d^ NGfc2Torus::getCoordPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Torus*)m_pEntity)->getCoordPtr(), false);
}

void NGfc2Torus::setRadius(NGfc2Double dValue)
{
    ((Gfc2Torus*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2Torus::getRadius()
{
    return ((Gfc2Torus*)m_pEntity)->getRadius();
}

bool NGfc2Torus::hasRadius()
{
    return ((Gfc2Torus*)m_pEntity)->hasRadius();
}

void NGfc2Torus::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2Torus*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2Torus::getClockSign()
{
    return ((Gfc2Torus*)m_pEntity)->getClockSign();
}

bool NGfc2Torus::hasClockSign()
{
    return ((Gfc2Torus*)m_pEntity)->hasClockSign();
}

void NGfc2Torus::setRangeV(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setRangeV(nValue);
}

glodon::objectbuf::EntityRef NGfc2Torus::getRangeV()
{
    return ((Gfc2Torus*)m_pEntity)->getRangeV();
}

bool NGfc2Torus::hasRangeV()
{
    return ((Gfc2Torus*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2Torus::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Torus*)m_pEntity)->getRangeVPtr(), false);
}

void NGfc2Torus::setCurve(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setCurve(nValue);
}

glodon::objectbuf::EntityRef NGfc2Torus::getCurve()
{
    return ((Gfc2Torus*)m_pEntity)->getCurve();
}

bool NGfc2Torus::hasCurve()
{
    return ((Gfc2Torus*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2Torus::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Torus*)m_pEntity)->getCurvePtr(), false);
}

