#include "NGfcExtrudedAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfcExtrudedAreaSolidShape::NGfcExtrudedAreaSolidShape()
{
    m_pEntity = new GfcExtrudedAreaSolidShape;
    m_bOwner = true;
}

NGfcExtrudedAreaSolidShape::NGfcExtrudedAreaSolidShape(bool bNoCreate):
    NGfcSweptAreaSolidShape(bNoCreate)
{
}

void NGfcExtrudedAreaSolidShape::setExtrudedDirection(gfc::engine::EntityRef nValue)
{
    ((GfcExtrudedAreaSolidShape*)m_pEntity)->setExtrudedDirection(nValue);
}

gfc::engine::EntityRef NGfcExtrudedAreaSolidShape::getExtrudedDirection()
{
    return ((GfcExtrudedAreaSolidShape*)m_pEntity)->getExtrudedDirection();
}

bool NGfcExtrudedAreaSolidShape::hasExtrudedDirection()
{
    return ((GfcExtrudedAreaSolidShape*)m_pEntity)->hasExtrudedDirection();
}

void NGfcExtrudedAreaSolidShape::setLen(NGfcDouble dValue)
{
    ((GfcExtrudedAreaSolidShape*)m_pEntity)->setLen(dValue);
}

NGfcDouble NGfcExtrudedAreaSolidShape::getLen()
{
    return ((GfcExtrudedAreaSolidShape*)m_pEntity)->getLen();
}

bool NGfcExtrudedAreaSolidShape::hasLen()
{
    return ((GfcExtrudedAreaSolidShape*)m_pEntity)->hasLen();
}

