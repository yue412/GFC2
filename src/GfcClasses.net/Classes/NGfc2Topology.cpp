#include "NGfc2Topology.h"

using namespace gfc::classes::x3;

NGfc2Topology::NGfc2Topology()
{
    m_pEntity = new Gfc2Topology;
    m_bOwner = true;
}

NGfc2Topology::NGfc2Topology(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

