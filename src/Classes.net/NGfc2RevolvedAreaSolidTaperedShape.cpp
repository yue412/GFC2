#include "NGfc2RevolvedAreaSolidTaperedShape.h"

using namespace gfc::classes::x3;

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

