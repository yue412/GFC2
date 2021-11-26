#include "NGfc2Box3d.h"

using namespace gfc::classes::x3;

NGfc2Box3d::NGfc2Box3d()
{
    m_pEntity = new Gfc2Box3d;
    m_bOwner = true;
}

NGfc2Box3d::NGfc2Box3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Box3d::setMin(gfc::engine::EntityRef nValue)
{
    ((Gfc2Box3d*)m_pEntity)->setMin(nValue);
}

gfc::engine::EntityRef NGfc2Box3d::getMin()
{
    return ((Gfc2Box3d*)m_pEntity)->getMin();
}

bool NGfc2Box3d::hasMin()
{
    return ((Gfc2Box3d*)m_pEntity)->hasMin();
}

void NGfc2Box3d::setMax(gfc::engine::EntityRef nValue)
{
    ((Gfc2Box3d*)m_pEntity)->setMax(nValue);
}

gfc::engine::EntityRef NGfc2Box3d::getMax()
{
    return ((Gfc2Box3d*)m_pEntity)->getMax();
}

bool NGfc2Box3d::hasMax()
{
    return ((Gfc2Box3d*)m_pEntity)->hasMax();
}

