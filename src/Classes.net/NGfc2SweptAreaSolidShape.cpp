#include "StdAfx.h"
#include "NGfc2SweptAreaSolidShape.h"
NGfc2SweptAreaSolidShape::NGfc2SweptAreaSolidShape()
{
    m_pEntity = new Gfc2SweptAreaSolidShape;
    m_bOwner = true;
}

NGfc2SweptAreaSolidShape::NGfc2SweptAreaSolidShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2SweptAreaSolidShape::setSweptArea(gfc::engine::EntityRef nValue)
{
    ((Gfc2SweptAreaSolidShape*)m_pEntity)->setSweptArea(nValue);
}

gfc::engine::EntityRef NGfc2SweptAreaSolidShape::getSweptArea()
{
    return ((Gfc2SweptAreaSolidShape*)m_pEntity)->getSweptArea();
}

bool NGfc2SweptAreaSolidShape::hasSweptArea()
{
    return ((Gfc2SweptAreaSolidShape*)m_pEntity)->hasSweptArea();
}

NGfc2Section^ NGfc2SweptAreaSolidShape::getSweptAreaPtr()
{
    return gcnew NGfc2Section(((Gfc2SweptAreaSolidShape*)m_pEntity)->getSweptAreaPtr(), false);
}

