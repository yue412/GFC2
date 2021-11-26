#include "NGfc2PlaneInfo.h"

using namespace gfc::classes::x3;

NGfc2PlaneInfo::NGfc2PlaneInfo()
{
    m_pEntity = new Gfc2PlaneInfo;
    m_bOwner = true;
}

NGfc2PlaneInfo::NGfc2PlaneInfo(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2PlaneInfo::setDirX(gfc::engine::EntityRef nValue)
{
    ((Gfc2PlaneInfo*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfc2PlaneInfo::getDirX()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->getDirX();
}

bool NGfc2PlaneInfo::hasDirX()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->hasDirX();
}

void NGfc2PlaneInfo::setDirY(gfc::engine::EntityRef nValue)
{
    ((Gfc2PlaneInfo*)m_pEntity)->setDirY(nValue);
}

gfc::engine::EntityRef NGfc2PlaneInfo::getDirY()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->getDirY();
}

bool NGfc2PlaneInfo::hasDirY()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->hasDirY();
}

void NGfc2PlaneInfo::setPos(gfc::engine::EntityRef nValue)
{
    ((Gfc2PlaneInfo*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfc2PlaneInfo::getPos()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->getPos();
}

bool NGfc2PlaneInfo::hasPos()
{
    return ((Gfc2PlaneInfo*)m_pEntity)->hasPos();
}

