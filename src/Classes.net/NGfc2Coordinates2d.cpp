#include "StdAfx.h"
#include "NGfc2Coordinates2d.h"
NGfc2Coordinates2d::NGfc2Coordinates2d()
{
    m_pEntity = new Gfc2Coordinates2d;
    m_bOwner = true;
}

NGfc2Coordinates2d::NGfc2Coordinates2d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Coordinates2d::setOrigin(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setOrigin(nValue);
}

gfc2::engine::EntityRef NGfc2Coordinates2d::getOrigin()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getOrigin();
}

bool NGfc2Coordinates2d::hasOrigin()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasOrigin();
}

NGfc2Vector2d^ NGfc2Coordinates2d::getOriginPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Coordinates2d*)m_pEntity)->getOriginPtr(), false);
}

void NGfc2Coordinates2d::setX(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setX(nValue);
}

gfc2::engine::EntityRef NGfc2Coordinates2d::getX()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getX();
}

bool NGfc2Coordinates2d::hasX()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasX();
}

NGfc2Vector2d^ NGfc2Coordinates2d::getXPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Coordinates2d*)m_pEntity)->getXPtr(), false);
}

void NGfc2Coordinates2d::setY(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setY(nValue);
}

gfc2::engine::EntityRef NGfc2Coordinates2d::getY()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getY();
}

bool NGfc2Coordinates2d::hasY()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasY();
}

NGfc2Vector2d^ NGfc2Coordinates2d::getYPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Coordinates2d*)m_pEntity)->getYPtr(), false);
}

