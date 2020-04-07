#include "StdAfx.h"
#include "NGfc2Polygon.h"
NGfc2Polygon::NGfc2Polygon()
{
    m_pEntity = new Gfc2Polygon;
    m_bOwner = true;
}

NGfc2Polygon::NGfc2Polygon(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

