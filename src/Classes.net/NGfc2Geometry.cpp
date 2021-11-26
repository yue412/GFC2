#include "NGfc2Geometry.h"

using namespace gfc::classes::x3;

NGfc2Geometry::NGfc2Geometry()
{
    m_pEntity = new Gfc2Geometry;
    m_bOwner = true;
}

NGfc2Geometry::NGfc2Geometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

