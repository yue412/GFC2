#include "NGfc2Arc3d.h"

using namespace gfc::classes::x3;

NGfc2Arc3d::NGfc2Arc3d()
{
    m_pEntity = new Gfc2Arc3d;
    m_bOwner = true;
}

NGfc2Arc3d::NGfc2Arc3d(void* pEntity, bool bOwner):
    NGfc2PlaneCurve3d(pEntity, bOwner)
{
}

