#include "NGfcRevolvedAreaSolidTaperedShape.h"

using namespace gfc::classes::x3;

NGfcRevolvedAreaSolidTaperedShape::NGfcRevolvedAreaSolidTaperedShape()
{
    m_pEntity = new GfcRevolvedAreaSolidTaperedShape;
    m_bOwner = true;
}

NGfcRevolvedAreaSolidTaperedShape::NGfcRevolvedAreaSolidTaperedShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRevolvedAreaSolidShape(pEntity, bOwner)
{
}

void NGfcRevolvedAreaSolidTaperedShape::setEndSweptArea(gfc::engine::EntityRef nValue)
{
    ((GfcRevolvedAreaSolidTaperedShape*)m_pEntity)->setEndSweptArea(nValue);
}

gfc::engine::EntityRef NGfcRevolvedAreaSolidTaperedShape::getEndSweptArea()
{
    return ((GfcRevolvedAreaSolidTaperedShape*)m_pEntity)->getEndSweptArea();
}

bool NGfcRevolvedAreaSolidTaperedShape::hasEndSweptArea()
{
    return ((GfcRevolvedAreaSolidTaperedShape*)m_pEntity)->hasEndSweptArea();
}

