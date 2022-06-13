#include "NGfcArc2d.h"

using namespace gfc::classes::x3;

NGfcArc2d::NGfcArc2d()
{
    m_pEntity = new GfcArc2d;
    m_bOwner = true;
}

NGfcArc2d::NGfcArc2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcArc2d::setCenterPt(gfc::engine::EntityRef nValue)
{
    ((GfcArc2d*)m_pEntity)->setCenterPt(nValue);
}

gfc::engine::EntityRef NGfcArc2d::getCenterPt()
{
    return ((GfcArc2d*)m_pEntity)->getCenterPt();
}

bool NGfcArc2d::hasCenterPt()
{
    return ((GfcArc2d*)m_pEntity)->hasCenterPt();
}

void NGfcArc2d::setRadius(NGfcDouble dValue)
{
    ((GfcArc2d*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcArc2d::getRadius()
{
    return ((GfcArc2d*)m_pEntity)->getRadius();
}

bool NGfcArc2d::hasRadius()
{
    return ((GfcArc2d*)m_pEntity)->hasRadius();
}

void NGfcArc2d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcArc2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcArc2d::getRange()
{
    return ((GfcArc2d*)m_pEntity)->getRange();
}

bool NGfcArc2d::hasRange()
{
    return ((GfcArc2d*)m_pEntity)->hasRange();
}

void NGfcArc2d::setClockSign(NGfcInteger nValue)
{
    ((GfcArc2d*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcArc2d::getClockSign()
{
    return ((GfcArc2d*)m_pEntity)->getClockSign();
}

bool NGfcArc2d::hasClockSign()
{
    return ((GfcArc2d*)m_pEntity)->hasClockSign();
}

