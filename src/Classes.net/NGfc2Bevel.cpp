#include "StdAfx.h"
#include "NGfc2Bevel.h"
NGfc2Bevel::NGfc2Bevel()
{
    m_pEntity = new Gfc2Bevel;
    m_bOwner = true;
}

NGfc2Bevel::NGfc2Bevel(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Bevel::setCoord(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setCoord(nValue);
}

gfc2::engine::EntityRef NGfc2Bevel::getCoord()
{
    return ((Gfc2Bevel*)m_pEntity)->getCoord();
}

bool NGfc2Bevel::hasCoord()
{
    return ((Gfc2Bevel*)m_pEntity)->hasCoord();
}

NGfc2Coordinates3d^ NGfc2Bevel::getCoordPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Bevel*)m_pEntity)->getCoordPtr(), false);
}

void NGfc2Bevel::setHeight(NGfc2Double dValue)
{
    ((Gfc2Bevel*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2Bevel::getHeight()
{
    return ((Gfc2Bevel*)m_pEntity)->getHeight();
}

bool NGfc2Bevel::hasHeight()
{
    return ((Gfc2Bevel*)m_pEntity)->hasHeight();
}

void NGfc2Bevel::setRangeV(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setRangeV(nValue);
}

gfc2::engine::EntityRef NGfc2Bevel::getRangeV()
{
    return ((Gfc2Bevel*)m_pEntity)->getRangeV();
}

bool NGfc2Bevel::hasRangeV()
{
    return ((Gfc2Bevel*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2Bevel::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Bevel*)m_pEntity)->getRangeVPtr(), false);
}

void NGfc2Bevel::setCurve(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setCurve(nValue);
}

gfc2::engine::EntityRef NGfc2Bevel::getCurve()
{
    return ((Gfc2Bevel*)m_pEntity)->getCurve();
}

bool NGfc2Bevel::hasCurve()
{
    return ((Gfc2Bevel*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2Bevel::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Bevel*)m_pEntity)->getCurvePtr(), false);
}

