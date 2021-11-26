#include "NGfc2Plane.h"

using namespace gfc::classes::x3;

NGfc2Plane::NGfc2Plane()
{
    m_pEntity = new Gfc2Plane;
    m_bOwner = true;
}

NGfc2Plane::NGfc2Plane(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Plane::setPos(gfc::engine::EntityRef nValue)
{
    ((Gfc2Plane*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfc2Plane::getPos()
{
    return ((Gfc2Plane*)m_pEntity)->getPos();
}

bool NGfc2Plane::hasPos()
{
    return ((Gfc2Plane*)m_pEntity)->hasPos();
}

void NGfc2Plane::setDirU(gfc::engine::EntityRef nValue)
{
    ((Gfc2Plane*)m_pEntity)->setDirU(nValue);
}

gfc::engine::EntityRef NGfc2Plane::getDirU()
{
    return ((Gfc2Plane*)m_pEntity)->getDirU();
}

bool NGfc2Plane::hasDirU()
{
    return ((Gfc2Plane*)m_pEntity)->hasDirU();
}

void NGfc2Plane::setDirV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Plane*)m_pEntity)->setDirV(nValue);
}

gfc::engine::EntityRef NGfc2Plane::getDirV()
{
    return ((Gfc2Plane*)m_pEntity)->getDirV();
}

bool NGfc2Plane::hasDirV()
{
    return ((Gfc2Plane*)m_pEntity)->hasDirV();
}

void NGfc2Plane::setRangeU(gfc::engine::EntityRef nValue)
{
    ((Gfc2Plane*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfc2Plane::getRangeU()
{
    return ((Gfc2Plane*)m_pEntity)->getRangeU();
}

bool NGfc2Plane::hasRangeU()
{
    return ((Gfc2Plane*)m_pEntity)->hasRangeU();
}

void NGfc2Plane::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Plane*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2Plane::getRangeV()
{
    return ((Gfc2Plane*)m_pEntity)->getRangeV();
}

bool NGfc2Plane::hasRangeV()
{
    return ((Gfc2Plane*)m_pEntity)->hasRangeV();
}

