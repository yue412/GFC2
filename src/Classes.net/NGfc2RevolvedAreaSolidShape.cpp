#include "NGfc2RevolvedAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfc2RevolvedAreaSolidShape::NGfc2RevolvedAreaSolidShape()
{
    m_pEntity = new Gfc2RevolvedAreaSolidShape;
    m_bOwner = true;
}

NGfc2RevolvedAreaSolidShape::NGfc2RevolvedAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2RevolvedAreaSolidShape::setLocation(gfc::engine::EntityRef nValue)
{
    ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->setLocation(nValue);
}

gfc::engine::EntityRef NGfc2RevolvedAreaSolidShape::getLocation()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->getLocation();
}

bool NGfc2RevolvedAreaSolidShape::hasLocation()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->hasLocation();
}

void NGfc2RevolvedAreaSolidShape::setAxis(gfc::engine::EntityRef nValue)
{
    ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->setAxis(nValue);
}

gfc::engine::EntityRef NGfc2RevolvedAreaSolidShape::getAxis()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->getAxis();
}

bool NGfc2RevolvedAreaSolidShape::hasAxis()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->hasAxis();
}

void NGfc2RevolvedAreaSolidShape::setAngle(NGfc2Double dValue)
{
    ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2RevolvedAreaSolidShape::getAngle()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->getAngle();
}

bool NGfc2RevolvedAreaSolidShape::hasAngle()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->hasAngle();
}

