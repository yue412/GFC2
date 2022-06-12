#include "NGfcPlane.h"

using namespace gfc::classes::x3;

NGfcPlane::NGfcPlane()
{
    m_pEntity = new GfcPlane;
    m_bOwner = true;
}

NGfcPlane::NGfcPlane(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcPlane::setPos(gfc::engine::EntityRef nValue)
{
    ((GfcPlane*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfcPlane::getPos()
{
    return ((GfcPlane*)m_pEntity)->getPos();
}

bool NGfcPlane::hasPos()
{
    return ((GfcPlane*)m_pEntity)->hasPos();
}

void NGfcPlane::setDirU(gfc::engine::EntityRef nValue)
{
    ((GfcPlane*)m_pEntity)->setDirU(nValue);
}

gfc::engine::EntityRef NGfcPlane::getDirU()
{
    return ((GfcPlane*)m_pEntity)->getDirU();
}

bool NGfcPlane::hasDirU()
{
    return ((GfcPlane*)m_pEntity)->hasDirU();
}

void NGfcPlane::setDirV(gfc::engine::EntityRef nValue)
{
    ((GfcPlane*)m_pEntity)->setDirV(nValue);
}

gfc::engine::EntityRef NGfcPlane::getDirV()
{
    return ((GfcPlane*)m_pEntity)->getDirV();
}

bool NGfcPlane::hasDirV()
{
    return ((GfcPlane*)m_pEntity)->hasDirV();
}

void NGfcPlane::setRangeU(gfc::engine::EntityRef nValue)
{
    ((GfcPlane*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfcPlane::getRangeU()
{
    return ((GfcPlane*)m_pEntity)->getRangeU();
}

bool NGfcPlane::hasRangeU()
{
    return ((GfcPlane*)m_pEntity)->hasRangeU();
}

void NGfcPlane::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcPlane*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcPlane::getRangeV()
{
    return ((GfcPlane*)m_pEntity)->getRangeV();
}

bool NGfcPlane::hasRangeV()
{
    return ((GfcPlane*)m_pEntity)->hasRangeV();
}

