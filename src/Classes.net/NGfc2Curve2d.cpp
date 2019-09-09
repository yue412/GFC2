#include "StdAfx.h"
#include "NGfc2Curve2d.h"
NGfc2Curve2d::NGfc2Curve2d()
{
    m_pEntity = new Gfc2Curve2d;
    m_bOwner = true;
}

NGfc2Curve2d::NGfc2Curve2d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

