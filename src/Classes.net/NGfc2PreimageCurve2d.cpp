#include "StdAfx.h"
#include "NGfc2PreimageCurve2d.h"
NGfc2PreimageCurve2d::NGfc2PreimageCurve2d()
{
    m_pEntity = new Gfc2PreimageCurve2d;
    m_bOwner = true;
}

NGfc2PreimageCurve2d::NGfc2PreimageCurve2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2PreimageCurve2d::setRange(gfc::engine::EntityRef nValue)
{
    ((Gfc2PreimageCurve2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfc2PreimageCurve2d::getRange()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->getRange();
}

bool NGfc2PreimageCurve2d::hasRange()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2PreimageCurve2d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2PreimageCurve2d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2PreimageCurve2d::setReversed(NGfc2Boolean bValue)
{
    ((Gfc2PreimageCurve2d*)m_pEntity)->setReversed(bValue);
}

NGfc2Boolean NGfc2PreimageCurve2d::getReversed()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->getReversed();
}

bool NGfc2PreimageCurve2d::hasReversed()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->hasReversed();
}

void NGfc2PreimageCurve2d::setBase(gfc::engine::EntityRef nValue)
{
    ((Gfc2PreimageCurve2d*)m_pEntity)->setBase(nValue);
}

gfc::engine::EntityRef NGfc2PreimageCurve2d::getBase()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->getBase();
}

bool NGfc2PreimageCurve2d::hasBase()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->hasBase();
}

NGfc2Surface^ NGfc2PreimageCurve2d::getBasePtr()
{
    return gcnew NGfc2Surface(((Gfc2PreimageCurve2d*)m_pEntity)->getBasePtr(), false);
}

void NGfc2PreimageCurve2d::setCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2PreimageCurve2d*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfc2PreimageCurve2d::getCurve()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->getCurve();
}

bool NGfc2PreimageCurve2d::hasCurve()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->hasCurve();
}

NGfc2Curve3d^ NGfc2PreimageCurve2d::getCurvePtr()
{
    return gcnew NGfc2Curve3d(((Gfc2PreimageCurve2d*)m_pEntity)->getCurvePtr(), false);
}

void NGfc2PreimageCurve2d::setTolerance(NGfc2Double dValue)
{
    ((Gfc2PreimageCurve2d*)m_pEntity)->setTolerance(dValue);
}

NGfc2Double NGfc2PreimageCurve2d::getTolerance()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->getTolerance();
}

bool NGfc2PreimageCurve2d::hasTolerance()
{
    return ((Gfc2PreimageCurve2d*)m_pEntity)->hasTolerance();
}

