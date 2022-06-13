#include "NGfcSweptAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfcSweptAreaSolidShape::NGfcSweptAreaSolidShape()
{
    m_pEntity = new GfcSweptAreaSolidShape;
    m_bOwner = true;
}

NGfcSweptAreaSolidShape::NGfcSweptAreaSolidShape(bool bNoCreate):
    NGfcSolidShape(bNoCreate)
{
}

void NGfcSweptAreaSolidShape::setSweptArea(gfc::engine::EntityRef nValue)
{
    ((GfcSweptAreaSolidShape*)m_pEntity)->setSweptArea(nValue);
}

gfc::engine::EntityRef NGfcSweptAreaSolidShape::getSweptArea()
{
    return ((GfcSweptAreaSolidShape*)m_pEntity)->getSweptArea();
}

bool NGfcSweptAreaSolidShape::hasSweptArea()
{
    return ((GfcSweptAreaSolidShape*)m_pEntity)->hasSweptArea();
}

