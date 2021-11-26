#include "NGfc2Vector3d.h"

using namespace gfc::classes::x3;

NGfc2Vector3d::NGfc2Vector3d()
{
    m_pEntity = new Gfc2Vector3d;
    m_bOwner = true;
}

NGfc2Vector3d::NGfc2Vector3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Vector3d::setX(NGfc2Double dValue)
{
    ((Gfc2Vector3d*)m_pEntity)->setX(dValue);
}

NGfc2Double NGfc2Vector3d::getX()
{
    return ((Gfc2Vector3d*)m_pEntity)->getX();
}

bool NGfc2Vector3d::hasX()
{
    return ((Gfc2Vector3d*)m_pEntity)->hasX();
}

void NGfc2Vector3d::setY(NGfc2Double dValue)
{
    ((Gfc2Vector3d*)m_pEntity)->setY(dValue);
}

NGfc2Double NGfc2Vector3d::getY()
{
    return ((Gfc2Vector3d*)m_pEntity)->getY();
}

bool NGfc2Vector3d::hasY()
{
    return ((Gfc2Vector3d*)m_pEntity)->hasY();
}

void NGfc2Vector3d::setZ(NGfc2Double dValue)
{
    ((Gfc2Vector3d*)m_pEntity)->setZ(dValue);
}

NGfc2Double NGfc2Vector3d::getZ()
{
    return ((Gfc2Vector3d*)m_pEntity)->getZ();
}

bool NGfc2Vector3d::hasZ()
{
    return ((Gfc2Vector3d*)m_pEntity)->hasZ();
}

