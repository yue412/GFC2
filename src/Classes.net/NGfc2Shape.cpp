#include "StdAfx.h"
#include "NGfc2Shape.h"
NGfc2Shape::NGfc2Shape()
{
    m_pEntity = new Gfc2Shape;
    m_bOwner = true;
}

NGfc2Shape::NGfc2Shape(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2Shape::setLocalCoordinate(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Shape*)m_pEntity)->setLocalCoordinate(nValue);
}

gfc2::engine::EntityRef NGfc2Shape::getLocalCoordinate()
{
    return ((Gfc2Shape*)m_pEntity)->getLocalCoordinate();
}

bool NGfc2Shape::hasLocalCoordinate()
{
    return ((Gfc2Shape*)m_pEntity)->hasLocalCoordinate();
}

NGfc2Coordinates3d^ NGfc2Shape::getLocalCoordinatePtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Shape*)m_pEntity)->getLocalCoordinatePtr(), false);
}

void NGfc2Shape::setBoundingBox(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Shape*)m_pEntity)->setBoundingBox(nValue);
}

gfc2::engine::EntityRef NGfc2Shape::getBoundingBox()
{
    return ((Gfc2Shape*)m_pEntity)->getBoundingBox();
}

bool NGfc2Shape::hasBoundingBox()
{
    return ((Gfc2Shape*)m_pEntity)->hasBoundingBox();
}

NGfc2Box3d^ NGfc2Shape::getBoundingBoxPtr()
{
    return gcnew NGfc2Box3d(((Gfc2Shape*)m_pEntity)->getBoundingBoxPtr(), false);
}

