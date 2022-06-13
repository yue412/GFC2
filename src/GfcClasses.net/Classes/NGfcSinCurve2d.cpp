#include "NGfcSinCurve2d.h"

using namespace gfc::classes::x3;

NGfcSinCurve2d::NGfcSinCurve2d()
{
    m_pEntity = new GfcSinCurve2d;
    m_bOwner = true;
}

NGfcSinCurve2d::NGfcSinCurve2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcSinCurve2d::setPos(gfc::engine::EntityRef nValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfcSinCurve2d::getPos()
{
    return ((GfcSinCurve2d*)m_pEntity)->getPos();
}

bool NGfcSinCurve2d::hasPos()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasPos();
}

void NGfcSinCurve2d::setDirX(gfc::engine::EntityRef nValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfcSinCurve2d::getDirX()
{
    return ((GfcSinCurve2d*)m_pEntity)->getDirX();
}

bool NGfcSinCurve2d::hasDirX()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasDirX();
}

void NGfcSinCurve2d::setA(NGfcDouble dValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setA(dValue);
}

NGfcDouble NGfcSinCurve2d::getA()
{
    return ((GfcSinCurve2d*)m_pEntity)->getA();
}

bool NGfcSinCurve2d::hasA()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasA();
}

void NGfcSinCurve2d::setB(NGfcDouble dValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setB(dValue);
}

NGfcDouble NGfcSinCurve2d::getB()
{
    return ((GfcSinCurve2d*)m_pEntity)->getB();
}

bool NGfcSinCurve2d::hasB()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasB();
}

void NGfcSinCurve2d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcSinCurve2d::getRange()
{
    return ((GfcSinCurve2d*)m_pEntity)->getRange();
}

bool NGfcSinCurve2d::hasRange()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasRange();
}

void NGfcSinCurve2d::setClockSign(NGfcInteger nValue)
{
    ((GfcSinCurve2d*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcSinCurve2d::getClockSign()
{
    return ((GfcSinCurve2d*)m_pEntity)->getClockSign();
}

bool NGfcSinCurve2d::hasClockSign()
{
    return ((GfcSinCurve2d*)m_pEntity)->hasClockSign();
}

