#include "NGfc2Coordinates3d.h"

using namespace gfc::classes::x3;

NGfc2Coordinates3d::NGfc2Coordinates3d()
{
    m_pEntity = new Gfc2Coordinates3d;
    m_bOwner = true;
}

NGfc2Coordinates3d::NGfc2Coordinates3d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Coordinates3d::setOrigin(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setOrigin(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates3d::getOrigin()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getOrigin();
}

bool NGfc2Coordinates3d::hasOrigin()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasOrigin();
}

void NGfc2Coordinates3d::setX(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setX(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates3d::getX()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getX();
}

bool NGfc2Coordinates3d::hasX()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasX();
}

void NGfc2Coordinates3d::setY(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setY(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates3d::getY()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getY();
}

bool NGfc2Coordinates3d::hasY()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasY();
}

void NGfc2Coordinates3d::setZ(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setZ(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates3d::getZ()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getZ();
}

bool NGfc2Coordinates3d::hasZ()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasZ();
}

