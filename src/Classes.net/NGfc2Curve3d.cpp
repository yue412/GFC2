#include "NGfc2Curve3d.h"

using namespace gfc::classes::x3;

NGfc2Curve3d::NGfc2Curve3d()
{
    m_pEntity = new Gfc2Curve3d;
    m_bOwner = true;
}

NGfc2Curve3d::NGfc2Curve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

