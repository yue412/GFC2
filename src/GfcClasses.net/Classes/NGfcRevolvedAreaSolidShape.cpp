#include "NGfcRevolvedAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfcRevolvedAreaSolidShape::NGfcRevolvedAreaSolidShape()
{
    m_pEntity = new GfcRevolvedAreaSolidShape;
    m_bOwner = true;
}

NGfcRevolvedAreaSolidShape::NGfcRevolvedAreaSolidShape(bool bNoCreate):
    NGfcSweptAreaSolidShape(bNoCreate)
{
}

void NGfcRevolvedAreaSolidShape::setLocation(gfc::engine::EntityRef nValue)
{
    ((GfcRevolvedAreaSolidShape*)m_pEntity)->setLocation(nValue);
}

gfc::engine::EntityRef NGfcRevolvedAreaSolidShape::getLocation()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->getLocation();
}

bool NGfcRevolvedAreaSolidShape::hasLocation()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->hasLocation();
}

void NGfcRevolvedAreaSolidShape::setAxis(gfc::engine::EntityRef nValue)
{
    ((GfcRevolvedAreaSolidShape*)m_pEntity)->setAxis(nValue);
}

gfc::engine::EntityRef NGfcRevolvedAreaSolidShape::getAxis()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->getAxis();
}

bool NGfcRevolvedAreaSolidShape::hasAxis()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->hasAxis();
}

void NGfcRevolvedAreaSolidShape::setAngle(NGfcDouble dValue)
{
    ((GfcRevolvedAreaSolidShape*)m_pEntity)->setAngle(dValue);
}

NGfcDouble NGfcRevolvedAreaSolidShape::getAngle()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->getAngle();
}

bool NGfcRevolvedAreaSolidShape::hasAngle()
{
    return ((GfcRevolvedAreaSolidShape*)m_pEntity)->hasAngle();
}

