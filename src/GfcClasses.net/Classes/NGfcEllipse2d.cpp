#include "NGfcEllipse2d.h"

using namespace gfc::classes::x3;

NGfcEllipse2d::NGfcEllipse2d()
{
    m_pEntity = new GfcEllipse2d;
    m_bOwner = true;
}

NGfcEllipse2d::NGfcEllipse2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcEllipse2d::setCenterPt(gfc::engine::EntityRef nValue)
{
    ((GfcEllipse2d*)m_pEntity)->setCenterPt(nValue);
}

gfc::engine::EntityRef NGfcEllipse2d::getCenterPt()
{
    return ((GfcEllipse2d*)m_pEntity)->getCenterPt();
}

bool NGfcEllipse2d::hasCenterPt()
{
    return ((GfcEllipse2d*)m_pEntity)->hasCenterPt();
}

void NGfcEllipse2d::setMajorAxis(gfc::engine::EntityRef nValue)
{
    ((GfcEllipse2d*)m_pEntity)->setMajorAxis(nValue);
}

gfc::engine::EntityRef NGfcEllipse2d::getMajorAxis()
{
    return ((GfcEllipse2d*)m_pEntity)->getMajorAxis();
}

bool NGfcEllipse2d::hasMajorAxis()
{
    return ((GfcEllipse2d*)m_pEntity)->hasMajorAxis();
}

void NGfcEllipse2d::setdMajorRad(NGfcDouble dValue)
{
    ((GfcEllipse2d*)m_pEntity)->setdMajorRad(dValue);
}

NGfcDouble NGfcEllipse2d::getdMajorRad()
{
    return ((GfcEllipse2d*)m_pEntity)->getdMajorRad();
}

bool NGfcEllipse2d::hasdMajorRad()
{
    return ((GfcEllipse2d*)m_pEntity)->hasdMajorRad();
}

void NGfcEllipse2d::setdMinorRad(NGfcDouble dValue)
{
    ((GfcEllipse2d*)m_pEntity)->setdMinorRad(dValue);
}

NGfcDouble NGfcEllipse2d::getdMinorRad()
{
    return ((GfcEllipse2d*)m_pEntity)->getdMinorRad();
}

bool NGfcEllipse2d::hasdMinorRad()
{
    return ((GfcEllipse2d*)m_pEntity)->hasdMinorRad();
}

void NGfcEllipse2d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcEllipse2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcEllipse2d::getRange()
{
    return ((GfcEllipse2d*)m_pEntity)->getRange();
}

bool NGfcEllipse2d::hasRange()
{
    return ((GfcEllipse2d*)m_pEntity)->hasRange();
}

void NGfcEllipse2d::setClockSign(NGfcInteger nValue)
{
    ((GfcEllipse2d*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcEllipse2d::getClockSign()
{
    return ((GfcEllipse2d*)m_pEntity)->getClockSign();
}

bool NGfcEllipse2d::hasClockSign()
{
    return ((GfcEllipse2d*)m_pEntity)->hasClockSign();
}

