#include "StdAfx.h"
#include "NGfc2Box3d.h"
NGfc2Box3d::NGfc2Box3d()
{
    m_pEntity = new Gfc2Box3d;
    m_bOwner = true;
}

NGfc2Box3d::NGfc2Box3d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Box3d::setMin(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Box3d*)m_pEntity)->setMin(nValue);
}

gfc2::engine::EntityRef NGfc2Box3d::getMin()
{
    return ((Gfc2Box3d*)m_pEntity)->getMin();
}

bool NGfc2Box3d::hasMin()
{
    return ((Gfc2Box3d*)m_pEntity)->hasMin();
}

NGfc2Vector3d^ NGfc2Box3d::getMinPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Box3d*)m_pEntity)->getMinPtr(), false);
}

void NGfc2Box3d::setMax(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Box3d*)m_pEntity)->setMax(nValue);
}

gfc2::engine::EntityRef NGfc2Box3d::getMax()
{
    return ((Gfc2Box3d*)m_pEntity)->getMax();
}

bool NGfc2Box3d::hasMax()
{
    return ((Gfc2Box3d*)m_pEntity)->hasMax();
}

NGfc2Vector3d^ NGfc2Box3d::getMaxPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Box3d*)m_pEntity)->getMaxPtr(), false);
}

