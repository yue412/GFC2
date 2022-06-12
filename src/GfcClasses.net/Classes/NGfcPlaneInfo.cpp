#include "NGfcPlaneInfo.h"

using namespace gfc::classes::x3;

NGfcPlaneInfo::NGfcPlaneInfo()
{
    m_pEntity = new GfcPlaneInfo;
    m_bOwner = true;
}

NGfcPlaneInfo::NGfcPlaneInfo(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcPlaneInfo::setDirX(gfc::engine::EntityRef nValue)
{
    ((GfcPlaneInfo*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfcPlaneInfo::getDirX()
{
    return ((GfcPlaneInfo*)m_pEntity)->getDirX();
}

bool NGfcPlaneInfo::hasDirX()
{
    return ((GfcPlaneInfo*)m_pEntity)->hasDirX();
}

void NGfcPlaneInfo::setDirY(gfc::engine::EntityRef nValue)
{
    ((GfcPlaneInfo*)m_pEntity)->setDirY(nValue);
}

gfc::engine::EntityRef NGfcPlaneInfo::getDirY()
{
    return ((GfcPlaneInfo*)m_pEntity)->getDirY();
}

bool NGfcPlaneInfo::hasDirY()
{
    return ((GfcPlaneInfo*)m_pEntity)->hasDirY();
}

void NGfcPlaneInfo::setPos(gfc::engine::EntityRef nValue)
{
    ((GfcPlaneInfo*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfcPlaneInfo::getPos()
{
    return ((GfcPlaneInfo*)m_pEntity)->getPos();
}

bool NGfcPlaneInfo::hasPos()
{
    return ((GfcPlaneInfo*)m_pEntity)->hasPos();
}

