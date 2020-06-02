#include "StdAfx.h"
#include "NGfc2RevolvedAreaSolidShape.h"
NGfc2RevolvedAreaSolidShape::NGfc2RevolvedAreaSolidShape()
{
    m_pEntity = new Gfc2RevolvedAreaSolidShape;
    m_bOwner = true;
}

NGfc2RevolvedAreaSolidShape::NGfc2RevolvedAreaSolidShape(void* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2RevolvedAreaSolidShape::setAxis(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->setAxis(nValue);
}

gfc2::engine::EntityRef NGfc2RevolvedAreaSolidShape::getAxis()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->getAxis();
}

bool NGfc2RevolvedAreaSolidShape::hasAxis()
{
    return ((Gfc2RevolvedAreaSolidShape*)m_pEntity)->hasAxis();
}

NGfc2Vector2d^ NGfc2RevolvedAreaSolidShape::getAxisPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2RevolvedAreaSolidShape*)m_pEntity)->getAxisPtr(), false);
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

