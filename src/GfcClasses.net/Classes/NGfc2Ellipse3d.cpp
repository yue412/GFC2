#include "NGfc2Ellipse3d.h"

using namespace gfc::classes::x3;

NGfc2Ellipse3d::NGfc2Ellipse3d()
{
    m_pEntity = new Gfc2Ellipse3d;
    m_bOwner = true;
}

NGfc2Ellipse3d::NGfc2Ellipse3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2PlaneCurve3d(pEntity, bOwner)
{
}

