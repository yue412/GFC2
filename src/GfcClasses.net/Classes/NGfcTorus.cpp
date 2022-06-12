#include "NGfcTorus.h"

using namespace gfc::classes::x3;

NGfcTorus::NGfcTorus()
{
    m_pEntity = new GfcTorus;
    m_bOwner = true;
}

NGfcTorus::NGfcTorus(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcTorus::setCoord(gfc::engine::EntityRef nValue)
{
    ((GfcTorus*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfcTorus::getCoord()
{
    return ((GfcTorus*)m_pEntity)->getCoord();
}

bool NGfcTorus::hasCoord()
{
    return ((GfcTorus*)m_pEntity)->hasCoord();
}

void NGfcTorus::setRadius(NGfcDouble dValue)
{
    ((GfcTorus*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcTorus::getRadius()
{
    return ((GfcTorus*)m_pEntity)->getRadius();
}

bool NGfcTorus::hasRadius()
{
    return ((GfcTorus*)m_pEntity)->hasRadius();
}

void NGfcTorus::setClockSign(NGfcInteger nValue)
{
    ((GfcTorus*)m_pEntity)->setClockSign(nValue);
}

NGfcInteger NGfcTorus::getClockSign()
{
    return ((GfcTorus*)m_pEntity)->getClockSign();
}

bool NGfcTorus::hasClockSign()
{
    return ((GfcTorus*)m_pEntity)->hasClockSign();
}

void NGfcTorus::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcTorus*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcTorus::getRangeV()
{
    return ((GfcTorus*)m_pEntity)->getRangeV();
}

bool NGfcTorus::hasRangeV()
{
    return ((GfcTorus*)m_pEntity)->hasRangeV();
}

void NGfcTorus::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcTorus*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcTorus::getCurve()
{
    return ((GfcTorus*)m_pEntity)->getCurve();
}

bool NGfcTorus::hasCurve()
{
    return ((GfcTorus*)m_pEntity)->hasCurve();
}

