#include "StdAfx.h"
#include "NGfc2CuboidBody.h"
NGfc2CuboidBody::NGfc2CuboidBody()
{
    m_pEntity = new Gfc2CuboidBody;
    m_bOwner = true;
}

NGfc2CuboidBody::NGfc2CuboidBody(void* pEntity, bool bOwner):
    NGfc2Body(pEntity, bOwner)
{
}

void NGfc2CuboidBody::setCoordinate(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CuboidBody*)m_pEntity)->setCoordinate(nValue);
}

glodon::objectbuf::EntityRef NGfc2CuboidBody::getCoordinate()
{
    return ((Gfc2CuboidBody*)m_pEntity)->getCoordinate();
}

bool NGfc2CuboidBody::hasCoordinate()
{
    return ((Gfc2CuboidBody*)m_pEntity)->hasCoordinate();
}

NGfc2Coordinates3d^ NGfc2CuboidBody::getCoordinatePtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2CuboidBody*)m_pEntity)->getCoordinatePtr(), false);
}

void NGfc2CuboidBody::setDimension(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CuboidBody*)m_pEntity)->setDimension(nValue);
}

glodon::objectbuf::EntityRef NGfc2CuboidBody::getDimension()
{
    return ((Gfc2CuboidBody*)m_pEntity)->getDimension();
}

bool NGfc2CuboidBody::hasDimension()
{
    return ((Gfc2CuboidBody*)m_pEntity)->hasDimension();
}

NGfc2Vector3d^ NGfc2CuboidBody::getDimensionPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2CuboidBody*)m_pEntity)->getDimensionPtr(), false);
}

