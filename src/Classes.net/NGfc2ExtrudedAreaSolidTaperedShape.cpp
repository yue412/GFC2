#include "NGfc2ExtrudedAreaSolidTaperedShape.h"

using namespace gfc::classes::x3;

NGfc2ExtrudedAreaSolidTaperedShape::NGfc2ExtrudedAreaSolidTaperedShape()
{
    m_pEntity = new Gfc2ExtrudedAreaSolidTaperedShape;
    m_bOwner = true;
}

NGfc2ExtrudedAreaSolidTaperedShape::NGfc2ExtrudedAreaSolidTaperedShape(void* pEntity, bool bOwner):
    NGfc2ExtrudedAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2ExtrudedAreaSolidTaperedShape::setEndSweptArea(gfc::engine::EntityRef nValue)
{
    ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->setEndSweptArea(nValue);
}

gfc::engine::EntityRef NGfc2ExtrudedAreaSolidTaperedShape::getEndSweptArea()
{
    return ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->getEndSweptArea();
}

bool NGfc2ExtrudedAreaSolidTaperedShape::hasEndSweptArea()
{
    return ((Gfc2ExtrudedAreaSolidTaperedShape*)m_pEntity)->hasEndSweptArea();
}

