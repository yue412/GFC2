#include "NGfcHelicoid.h"

using namespace gfc::classes::x3;

NGfcHelicoid::NGfcHelicoid()
{
    m_pEntity = new GfcHelicoid;
    m_bOwner = true;
}

NGfcHelicoid::NGfcHelicoid(bool bNoCreate):
    NGfcSurface(bNoCreate)
{
}

void NGfcHelicoid::setCoord(gfc::engine::EntityRef nValue)
{
    ((GfcHelicoid*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfcHelicoid::getCoord()
{
    return ((GfcHelicoid*)m_pEntity)->getCoord();
}

bool NGfcHelicoid::hasCoord()
{
    return ((GfcHelicoid*)m_pEntity)->hasCoord();
}

void NGfcHelicoid::setRadius(NGfcDouble dValue)
{
    ((GfcHelicoid*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcHelicoid::getRadius()
{
    return ((GfcHelicoid*)m_pEntity)->getRadius();
}

bool NGfcHelicoid::hasRadius()
{
    return ((GfcHelicoid*)m_pEntity)->hasRadius();
}

void NGfcHelicoid::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcHelicoid*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcHelicoid::getRangeV()
{
    return ((GfcHelicoid*)m_pEntity)->getRangeV();
}

bool NGfcHelicoid::hasRangeV()
{
    return ((GfcHelicoid*)m_pEntity)->hasRangeV();
}

void NGfcHelicoid::setClockSign(NGfcInteger nValue)
{
    ((GfcHelicoid*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcHelicoid::getClockSign()
{
    return ((GfcHelicoid*)m_pEntity)->getClockSign();
}

bool NGfcHelicoid::hasClockSign()
{
    return ((GfcHelicoid*)m_pEntity)->hasClockSign();
}

void NGfcHelicoid::setHeightCoef(NGfcDouble dValue)
{
    ((GfcHelicoid*)m_pEntity)->setHeightCoef(dValue);
}

NGfcDouble NGfcHelicoid::getHeightCoef()
{
    return ((GfcHelicoid*)m_pEntity)->getHeightCoef();
}

bool NGfcHelicoid::hasHeightCoef()
{
    return ((GfcHelicoid*)m_pEntity)->hasHeightCoef();
}

void NGfcHelicoid::setRadiusCoef(NGfcDouble dValue)
{
    ((GfcHelicoid*)m_pEntity)->setRadiusCoef(dValue);
}

NGfcDouble NGfcHelicoid::getRadiusCoef()
{
    return ((GfcHelicoid*)m_pEntity)->getRadiusCoef();
}

bool NGfcHelicoid::hasRadiusCoef()
{
    return ((GfcHelicoid*)m_pEntity)->hasRadiusCoef();
}

void NGfcHelicoid::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcHelicoid*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcHelicoid::getCurve()
{
    return ((GfcHelicoid*)m_pEntity)->getCurve();
}

bool NGfcHelicoid::hasCurve()
{
    return ((GfcHelicoid*)m_pEntity)->hasCurve();
}

