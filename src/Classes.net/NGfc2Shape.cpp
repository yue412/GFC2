#include "NGfc2Shape.h"

using namespace gfc::classes::x3;

NGfc2Shape::NGfc2Shape()
{
    m_pEntity = new Gfc2Shape;
    m_bOwner = true;
}

NGfc2Shape::NGfc2Shape(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2Shape::setLocalCoordinate(gfc::engine::EntityRef nValue)
{
    ((Gfc2Shape*)m_pEntity)->setLocalCoordinate(nValue);
}

gfc::engine::EntityRef NGfc2Shape::getLocalCoordinate()
{
    return ((Gfc2Shape*)m_pEntity)->getLocalCoordinate();
}

bool NGfc2Shape::hasLocalCoordinate()
{
    return ((Gfc2Shape*)m_pEntity)->hasLocalCoordinate();
}

void NGfc2Shape::setBoundingBox(gfc::engine::EntityRef nValue)
{
    ((Gfc2Shape*)m_pEntity)->setBoundingBox(nValue);
}

gfc::engine::EntityRef NGfc2Shape::getBoundingBox()
{
    return ((Gfc2Shape*)m_pEntity)->getBoundingBox();
}

bool NGfc2Shape::hasBoundingBox()
{
    return ((Gfc2Shape*)m_pEntity)->hasBoundingBox();
}

