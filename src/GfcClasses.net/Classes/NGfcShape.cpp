#include "NGfcShape.h"

using namespace gfc::classes::x3;

NGfcShape::NGfcShape()
{
    m_pEntity = new GfcShape;
    m_bOwner = true;
}

NGfcShape::NGfcShape(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcShape::setLocalCoordinate(gfc::engine::EntityRef nValue)
{
    ((GfcShape*)m_pEntity)->setLocalCoordinate(nValue);
}

gfc::engine::EntityRef NGfcShape::getLocalCoordinate()
{
    return ((GfcShape*)m_pEntity)->getLocalCoordinate();
}

bool NGfcShape::hasLocalCoordinate()
{
    return ((GfcShape*)m_pEntity)->hasLocalCoordinate();
}

void NGfcShape::setBoundingBox(gfc::engine::EntityRef nValue)
{
    ((GfcShape*)m_pEntity)->setBoundingBox(nValue);
}

gfc::engine::EntityRef NGfcShape::getBoundingBox()
{
    return ((GfcShape*)m_pEntity)->getBoundingBox();
}

bool NGfcShape::hasBoundingBox()
{
    return ((GfcShape*)m_pEntity)->hasBoundingBox();
}

