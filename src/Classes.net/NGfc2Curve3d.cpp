#include "StdAfx.h"
#include "NGfc2Curve3d.h"
NGfc2Curve3d::NGfc2Curve3d()
{
    m_pEntity = new Gfc2Curve3d;
    m_bOwner = true;
}

NGfc2Curve3d::NGfc2Curve3d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

