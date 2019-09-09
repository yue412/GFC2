#include "StdAfx.h"
#include "NGfc2Sphere.h"
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

void NGfc2Sphere::setCoords(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setCoords(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sphere::getCoords()
{
    return ((Gfc2Sphere*)m_pEntity)->getCoords();
}

bool NGfc2Sphere::hasCoords()
{
    return ((Gfc2Sphere*)m_pEntity)->hasCoords();
}

NGfc2Coordinates3d^ NGfc2Sphere::getCoordsPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Sphere*)m_pEntity)->getCoordsPtr(), false);
}

void NGfc2Sphere::setRangeU(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setRangeU(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sphere::getRangeU()
{
    return ((Gfc2Sphere*)m_pEntity)->getRangeU();
}

bool NGfc2Sphere::hasRangeU()
{
    return ((Gfc2Sphere*)m_pEntity)->hasRangeU();
}

NGfc2Intervald^ NGfc2Sphere::getRangeUPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Sphere*)m_pEntity)->getRangeUPtr(), false);
}

void NGfc2Sphere::setRangeV(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sphere*)m_pEntity)->setRangeV(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sphere::getRangeV()
{
    return ((Gfc2Sphere*)m_pEntity)->getRangeV();
}

bool NGfc2Sphere::hasRangeV()
{
    return ((Gfc2Sphere*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2Sphere::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Sphere*)m_pEntity)->getRangeVPtr(), false);
}

