#include "NGfcCylinder.h"

using namespace gfc::classes::x3;

NGfcCylinder::NGfcCylinder()
{
    m_pEntity = new GfcCylinder;
    m_bOwner = true;
}

NGfcCylinder::NGfcCylinder(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcCylinder::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getRangeV()
{
    return ((GfcCylinder*)m_pEntity)->getRangeV();
}

bool NGfcCylinder::hasRangeV()
{
    return ((GfcCylinder*)m_pEntity)->hasRangeV();
}

void NGfcCylinder::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getCurve()
{
    return ((GfcCylinder*)m_pEntity)->getCurve();
}

bool NGfcCylinder::hasCurve()
{
    return ((GfcCylinder*)m_pEntity)->hasCurve();
}

void NGfcCylinder::setDirX(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getDirX()
{
    return ((GfcCylinder*)m_pEntity)->getDirX();
}

bool NGfcCylinder::hasDirX()
{
    return ((GfcCylinder*)m_pEntity)->hasDirX();
}

void NGfcCylinder::setDirY(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setDirY(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getDirY()
{
    return ((GfcCylinder*)m_pEntity)->getDirY();
}

bool NGfcCylinder::hasDirY()
{
    return ((GfcCylinder*)m_pEntity)->hasDirY();
}

void NGfcCylinder::setDirZ(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setDirZ(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getDirZ()
{
    return ((GfcCylinder*)m_pEntity)->getDirZ();
}

bool NGfcCylinder::hasDirZ()
{
    return ((GfcCylinder*)m_pEntity)->hasDirZ();
}

void NGfcCylinder::setPos(gfc::engine::EntityRef nValue)
{
    ((GfcCylinder*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfcCylinder::getPos()
{
    return ((GfcCylinder*)m_pEntity)->getPos();
}

bool NGfcCylinder::hasPos()
{
    return ((GfcCylinder*)m_pEntity)->hasPos();
}

