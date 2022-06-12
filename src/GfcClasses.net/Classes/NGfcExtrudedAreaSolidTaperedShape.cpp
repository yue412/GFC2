#include "NGfcExtrudedAreaSolidTaperedShape.h"

using namespace gfc::classes::x3;

NGfcExtrudedAreaSolidTaperedShape::NGfcExtrudedAreaSolidTaperedShape()
{
    m_pEntity = new GfcExtrudedAreaSolidTaperedShape;
    m_bOwner = true;
}

NGfcExtrudedAreaSolidTaperedShape::NGfcExtrudedAreaSolidTaperedShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcExtrudedAreaSolidShape(pEntity, bOwner)
{
}

void NGfcExtrudedAreaSolidTaperedShape::setEndSweptArea(gfc::engine::EntityRef nValue)
{
    ((GfcExtrudedAreaSolidTaperedShape*)m_pEntity)->setEndSweptArea(nValue);
}

gfc::engine::EntityRef NGfcExtrudedAreaSolidTaperedShape::getEndSweptArea()
{
    return ((GfcExtrudedAreaSolidTaperedShape*)m_pEntity)->getEndSweptArea();
}

bool NGfcExtrudedAreaSolidTaperedShape::hasEndSweptArea()
{
    return ((GfcExtrudedAreaSolidTaperedShape*)m_pEntity)->hasEndSweptArea();
}

