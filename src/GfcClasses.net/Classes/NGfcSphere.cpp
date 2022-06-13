#include "NGfcSphere.h"

using namespace gfc::classes::x3;

NGfcSphere::NGfcSphere()
{
    m_pEntity = new GfcSphere;
    m_bOwner = true;
}

NGfcSphere::NGfcSphere(bool bNoCreate):
    NGfcSurface(bNoCreate)
{
}

void NGfcSphere::setRadius(NGfcDouble dValue)
{
    ((GfcSphere*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcSphere::getRadius()
{
    return ((GfcSphere*)m_pEntity)->getRadius();
}

bool NGfcSphere::hasRadius()
{
    return ((GfcSphere*)m_pEntity)->hasRadius();
}

void NGfcSphere::setCoords(gfc::engine::EntityRef nValue)
{
    ((GfcSphere*)m_pEntity)->setCoords(nValue);
}

gfc::engine::EntityRef NGfcSphere::getCoords()
{
    return ((GfcSphere*)m_pEntity)->getCoords();
}

bool NGfcSphere::hasCoords()
{
    return ((GfcSphere*)m_pEntity)->hasCoords();
}

void NGfcSphere::setRangeU(gfc::engine::EntityRef nValue)
{
    ((GfcSphere*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfcSphere::getRangeU()
{
    return ((GfcSphere*)m_pEntity)->getRangeU();
}

bool NGfcSphere::hasRangeU()
{
    return ((GfcSphere*)m_pEntity)->hasRangeU();
}

void NGfcSphere::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcSphere*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcSphere::getRangeV()
{
    return ((GfcSphere*)m_pEntity)->getRangeV();
}

bool NGfcSphere::hasRangeV()
{
    return ((GfcSphere*)m_pEntity)->hasRangeV();
}

