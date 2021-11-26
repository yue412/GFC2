#include "NGfc2Sphere.h"

using namespace gfc::classes::x3;

NGfc2Sphere::NGfc2Sphere()
{
    m_pEntity = new Gfc2Sphere;
    m_bOwner = true;
}

NGfc2Sphere::NGfc2Sphere(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Sphere::setRadius(NGfc2Double dValue)
{
    ((Gfc2Sphere*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2Sphere::getRadius()
{
    return ((Gfc2Sphere*)m_pEntity)->getRadius();
}

bool NGfc2Sphere::hasRadius()
{
    return ((Gfc2Sphere*)m_pEntity)->hasRadius();
}

void NGfc2Sphere::setCoords(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setCoords(nValue);
}

gfc::engine::EntityRef NGfc2Sphere::getCoords()
{
    return ((Gfc2Sphere*)m_pEntity)->getCoords();
}

bool NGfc2Sphere::hasCoords()
{
    return ((Gfc2Sphere*)m_pEntity)->hasCoords();
}

void NGfc2Sphere::setRangeU(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfc2Sphere::getRangeU()
{
    return ((Gfc2Sphere*)m_pEntity)->getRangeU();
}

bool NGfc2Sphere::hasRangeU()
{
    return ((Gfc2Sphere*)m_pEntity)->hasRangeU();
}

void NGfc2Sphere::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2Sphere::getRangeV()
{
    return ((Gfc2Sphere*)m_pEntity)->getRangeV();
}

bool NGfc2Sphere::hasRangeV()
{
    return ((Gfc2Sphere*)m_pEntity)->hasRangeV();
}

