#include "NGfc2Polygon.h"

using namespace gfc::classes::x3;

NGfc2Polygon::NGfc2Polygon()
{
    m_pEntity = new Gfc2Polygon;
    m_bOwner = true;
}

NGfc2Polygon::NGfc2Polygon(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

