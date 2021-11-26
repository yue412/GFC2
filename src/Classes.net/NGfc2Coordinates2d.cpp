#include "NGfc2Coordinates2d.h"

using namespace gfc::classes::x3;

NGfc2Coordinates2d::NGfc2Coordinates2d()
{
    m_pEntity = new Gfc2Coordinates2d;
    m_bOwner = true;
}

NGfc2Coordinates2d::NGfc2Coordinates2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Coordinates2d::setOrigin(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setOrigin(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates2d::getOrigin()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getOrigin();
}

bool NGfc2Coordinates2d::hasOrigin()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasOrigin();
}

void NGfc2Coordinates2d::setX(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setX(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates2d::getX()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getX();
}

bool NGfc2Coordinates2d::hasX()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasX();
}

void NGfc2Coordinates2d::setY(gfc::engine::EntityRef nValue)
{
    ((Gfc2Coordinates2d*)m_pEntity)->setY(nValue);
}

gfc::engine::EntityRef NGfc2Coordinates2d::getY()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->getY();
}

bool NGfc2Coordinates2d::hasY()
{
    return ((Gfc2Coordinates2d*)m_pEntity)->hasY();
}

