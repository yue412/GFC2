#include "StdAfx.h"
#include "NGfc2PlaneInfo.h"
NGfc2PlaneInfo::NGfc2PlaneInfo()
{
    m_pEntity = new Gfc2PlaneInfo;
    m_bOwner = true;
}

NGfc2PlaneInfo::NGfc2PlaneInfo(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
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

NGfc2Vector3d^ NGfc2PlaneInfo::getDirXPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2PlaneInfo*)m_pEntity)->getDirXPtr(), false);
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

NGfc2Vector3d^ NGfc2PlaneInfo::getDirYPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2PlaneInfo*)m_pEntity)->getDirYPtr(), false);
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

NGfc2Vector3d^ NGfc2PlaneInfo::getPosPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2PlaneInfo*)m_pEntity)->getPosPtr(), false);
}

