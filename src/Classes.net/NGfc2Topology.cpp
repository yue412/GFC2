#include "StdAfx.h"
#include "NGfc2Topology.h"
NGfc2Topology::NGfc2Topology()
{
    m_pEntity = new Gfc2Topology;
    m_bOwner = true;
}

NGfc2Topology::NGfc2Topology(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

