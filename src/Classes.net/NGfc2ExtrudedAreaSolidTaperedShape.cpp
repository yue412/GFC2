#include "StdAfx.h"
#include "NGfc2ExtrudedAreaSolidTaperedShape.h"
NGfc2ExtrudedAreaSolidTaperedShape::NGfc2ExtrudedAreaSolidTaperedShape()
{
    m_pEntity = new Gfc2ExtrudedAreaSolidTaperedShape;
    m_bOwner = true;
}

NGfc2ExtrudedAreaSolidTaperedShape::NGfc2ExtrudedAreaSolidTaperedShape(void* pEntity, bool bOwner):
    NGfc2ExtrudedAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2ExtrudedAreaSolidTaperedShape::setEndSweptArea(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->setEndSweptArea(nValue);
}

glodon::objectbuf::EntityRef NGfc2ExtrudedAreaSolidTaperedShape::getEndSweptArea()
{
    return ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->getEndSweptArea();
}

bool NGfc2ExtrudedAreaSolidTaperedShape::hasEndSweptArea()
{
    return ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->hasEndSweptArea();
}

NGfc2Section^ NGfc2ExtrudedAreaSolidTaperedShape::getEndSweptAreaPtr()
{
    return gcnew NGfc2Section(((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->getEndSweptAreaPtr(), false);
}

