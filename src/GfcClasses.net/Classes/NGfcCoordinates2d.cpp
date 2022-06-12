#include "NGfcCoordinates2d.h"

using namespace gfc::classes::x3;

NGfcCoordinates2d::NGfcCoordinates2d()
{
    m_pEntity = new GfcCoordinates2d;
    m_bOwner = true;
}

NGfcCoordinates2d::NGfcCoordinates2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcGeometry(pEntity, bOwner)
{
}

void NGfcCoordinates2d::setOrigin(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates2d*)m_pEntity)->setOrigin(nValue);
}

gfc::engine::EntityRef NGfcCoordinates2d::getOrigin()
{
    return ((GfcCoordinates2d*)m_pEntity)->getOrigin();
}

bool NGfcCoordinates2d::hasOrigin()
{
    return ((GfcCoordinates2d*)m_pEntity)->hasOrigin();
}

void NGfcCoordinates2d::setX(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates2d*)m_pEntity)->setX(nValue);
}

gfc::engine::EntityRef NGfcCoordinates2d::getX()
{
    return ((GfcCoordinates2d*)m_pEntity)->getX();
}

bool NGfcCoordinates2d::hasX()
{
    return ((GfcCoordinates2d*)m_pEntity)->hasX();
}

void NGfcCoordinates2d::setY(gfc::engine::EntityRef nValue)
{
    ((GfcCoordinates2d*)m_pEntity)->setY(nValue);
}

gfc::engine::EntityRef NGfcCoordinates2d::getY()
{
    return ((GfcCoordinates2d*)m_pEntity)->getY();
}

bool NGfcCoordinates2d::hasY()
{
    return ((GfcCoordinates2d*)m_pEntity)->hasY();
}

