#include "StdAfx.h"
#include "NGfc2Ellipse3d.h"
NGfc2Ellipse3d::NGfc2Ellipse3d()
{
    m_pEntity = new Gfc2Ellipse3d;
    m_bOwner = true;
}

NGfc2Ellipse3d::NGfc2Ellipse3d(void* pEntity, bool bOwner):
    NGfc2PlaneCurve3d(pEntity, bOwner)
{
}

