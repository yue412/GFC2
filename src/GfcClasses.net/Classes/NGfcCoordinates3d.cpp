#include "NGfcCoordinates3d.h"

using namespace gfc::classes::x3;

NGfcCoordinates3d::NGfcCoordinates3d()
{
    m_pEntity = new GfcCoordinates3d;
    m_bOwner = true;
}

NGfcCoordinates3d::NGfcCoordinates3d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

void NGfcCoordinates3d::setOrigin(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates3d*)m_pEntity)->setOrigin(nValue);
}

gfc::engine::EntityRef NGfcCoordinates3d::getOrigin()
{
    return ((GfcCoordinates3d*)m_pEntity)->getOrigin();
}

bool NGfcCoordinates3d::hasOrigin()
{
    return ((GfcCoordinates3d*)m_pEntity)->hasOrigin();
}

void NGfcCoordinates3d::setX(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates3d*)m_pEntity)->setX(nValue);
}

gfc::engine::EntityRef NGfcCoordinates3d::getX()
{
    return ((GfcCoordinates3d*)m_pEntity)->getX();
}

bool NGfcCoordinates3d::hasX()
{
    return ((GfcCoordinates3d*)m_pEntity)->hasX();
}

void NGfcCoordinates3d::setY(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates3d*)m_pEntity)->setY(nValue);
}

gfc::engine::EntityRef NGfcCoordinates3d::getY()
{
    return ((GfcCoordinates3d*)m_pEntity)->getY();
}

bool NGfcCoordinates3d::hasY()
{
    return ((GfcCoordinates3d*)m_pEntity)->hasY();
}

void NGfcCoordinates3d::setZ(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates3d*)m_pEntity)->setZ(nValue);
}

gfc::engine::EntityRef NGfcCoordinates3d::getZ()
{
    return ((GfcCoordinates3d*)m_pEntity)->getZ();
}

bool NGfcCoordinates3d::hasZ()
{
    return ((GfcCoordinates3d*)m_pEntity)->hasZ();
}

