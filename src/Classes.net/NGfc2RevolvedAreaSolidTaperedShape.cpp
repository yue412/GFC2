#include "StdAfx.h"
#include "NGfc2RevolvedAreaSolidTaperedShape.h"
NGfc2RevolvedAreaSolidTaperedShape::NGfc2RevolvedAreaSolidTaperedShape()
{
    m_pEntity = new Gfc2RevolvedAreaSolidTaperedShape;
    m_bOwner = true;
}

NGfc2RevolvedAreaSolidTaperedShape::NGfc2RevolvedAreaSolidTaperedShape(void* pEntity, bool bOwner):
    NGfc2RevolvedAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2RevolvedAreaSolidTaperedShape::setEndSweptArea(gfc::engine::EntityRef nValue)
{
    ((Gfc2RevolvedAreaSolidTaperedShape*)m_pEntity)->setEndSweptArea(nValue);
}

gfc::engine::EntityRef NGfc2RevolvedAreaSolidTaperedShape::getEndSweptArea()
{
    return ((Gfc2RevolvedAreaSolidTaperedShape*)m_pEntity)->getEndSweptArea();
}

bool NGfc2RevolvedAreaSolidTaperedShape::hasEndSweptArea()
{
    return ((Gfc2RevolvedAreaSolidTaperedShape*)m_pEntity)->hasEndSweptArea();
}

NGfc2Section^ NGfc2RevolvedAreaSolidTaperedShape::getEndSweptAreaPtr()
{
    return gcnew NGfc2Section(((Gfc2RevolvedAreaSolidTaperedShape*)m_pEntity)->getEndSweptAreaPtr(), false);
}

