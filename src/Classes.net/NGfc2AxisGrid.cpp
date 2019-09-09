#include "StdAfx.h"
#include "NGfc2AxisGrid.h"
NGfc2AxisGrid::NGfc2AxisGrid()
{
    m_pEntity = new Gfc2AxisGrid;
    m_bOwner = true;
}

NGfc2AxisGrid::NGfc2AxisGrid(void* pEntity, bool bOwner):
    NGfc2Entity(pEntity, bOwner)
{
}

