#include "StdAfx.h"
#include "NGfc2ExtrudedAreaSolidShape.h"
NGfc2ExtrudedAreaSolidShape::NGfc2ExtrudedAreaSolidShape()
{
    m_pEntity = new Gfc2ExtrudedAreaSolidShape;
    m_bOwner = true;
}

NGfc2ExtrudedAreaSolidShape::NGfc2ExtrudedAreaSolidShape(void* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2ExtrudedAreaSolidShape::setExtrudedDirection(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->setExtrudedDirection(nValue);
}

gfc2::engine::EntityRef NGfc2ExtrudedAreaSolidShape::getExtrudedDirection()
{
    return ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->getExtrudedDirection();
}

bool NGfc2ExtrudedAreaSolidShape::hasExtrudedDirection()
{
    return ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->hasExtrudedDirection();
}

NGfc2Vector3d^ NGfc2ExtrudedAreaSolidShape::getExtrudedDirectionPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->getExtrudedDirectionPtr(), false);
}

void NGfc2ExtrudedAreaSolidShape::setLength(NGfc2Double dValue)
{
    ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->setLength(dValue);
}

NGfc2Double NGfc2ExtrudedAreaSolidShape::getLength()
{
    return ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->getLength();
}

bool NGfc2ExtrudedAreaSolidShape::hasLength()
{
    return ((Gfc2ExtrudedAreaSolidShape*)m_pEntity)->hasLength();
}

