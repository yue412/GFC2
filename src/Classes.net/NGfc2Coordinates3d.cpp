#include "StdAfx.h"
#include "NGfc2Coordinates3d.h"
NGfc2Coordinates3d::NGfc2Coordinates3d()
{
    m_pEntity = new Gfc2Coordinates3d;
    m_bOwner = true;
}

NGfc2Coordinates3d::NGfc2Coordinates3d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Coordinates3d::setOrigin(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setOrigin(nValue);
}

glodon::objectbuf::EntityRef NGfc2Coordinates3d::getOrigin()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getOrigin();
}

bool NGfc2Coordinates3d::hasOrigin()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasOrigin();
}

NGfc2Vector3d^ NGfc2Coordinates3d::getOriginPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Coordinates3d*)m_pEntity)->getOriginPtr(), false);
}

void NGfc2Coordinates3d::setX(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setX(nValue);
}

glodon::objectbuf::EntityRef NGfc2Coordinates3d::getX()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getX();
}

bool NGfc2Coordinates3d::hasX()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasX();
}

NGfc2Vector3d^ NGfc2Coordinates3d::getXPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Coordinates3d*)m_pEntity)->getXPtr(), false);
}

void NGfc2Coordinates3d::setY(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setY(nValue);
}

glodon::objectbuf::EntityRef NGfc2Coordinates3d::getY()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getY();
}

bool NGfc2Coordinates3d::hasY()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasY();
}

NGfc2Vector3d^ NGfc2Coordinates3d::getYPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Coordinates3d*)m_pEntity)->getYPtr(), false);
}

void NGfc2Coordinates3d::setZ(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Coordinates3d*)m_pEntity)->setZ(nValue);
}

glodon::objectbuf::EntityRef NGfc2Coordinates3d::getZ()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->getZ();
}

bool NGfc2Coordinates3d::hasZ()
{
    return ((Gfc2Coordinates3d*)m_pEntity)->hasZ();
}

NGfc2Vector3d^ NGfc2Coordinates3d::getZPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Coordinates3d*)m_pEntity)->getZPtr(), false);
}

