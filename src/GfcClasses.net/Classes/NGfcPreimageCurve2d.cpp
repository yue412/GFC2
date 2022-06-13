#include "NGfcPreimageCurve2d.h"

using namespace gfc::classes::x3;

NGfcPreimageCurve2d::NGfcPreimageCurve2d()
{
    m_pEntity = new GfcPreimageCurve2d;
    m_bOwner = true;
}

NGfcPreimageCurve2d::NGfcPreimageCurve2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcPreimageCurve2d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcPreimageCurve2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcPreimageCurve2d::getRange()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->getRange();
}

bool NGfcPreimageCurve2d::hasRange()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->hasRange();
}

void NGfcPreimageCurve2d::setReversed(NGfcBoolean bValue)
{
    ((GfcPreimageCurve2d*)m_pEntity)->setReversed(bValue);
}

NGfcBoolean NGfcPreimageCurve2d::getReversed()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->getReversed();
}

bool NGfcPreimageCurve2d::hasReversed()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->hasReversed();
}

void NGfcPreimageCurve2d::setBase(gfc::engine::EntityRef nValue)
{
    ((GfcPreimageCurve2d*)m_pEntity)->setBase(nValue);
}

gfc::engine::EntityRef NGfcPreimageCurve2d::getBase()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->getBase();
}

bool NGfcPreimageCurve2d::hasBase()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->hasBase();
}

void NGfcPreimageCurve2d::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcPreimageCurve2d*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcPreimageCurve2d::getCurve()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->getCurve();
}

bool NGfcPreimageCurve2d::hasCurve()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->hasCurve();
}

void NGfcPreimageCurve2d::setTolerance(NGfcDouble dValue)
{
    ((GfcPreimageCurve2d*)m_pEntity)->setTolerance(dValue);
}

NGfcDouble NGfcPreimageCurve2d::getTolerance()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->getTolerance();
}

bool NGfcPreimageCurve2d::hasTolerance()
{
    return ((GfcPreimageCurve2d*)m_pEntity)->hasTolerance();
}

