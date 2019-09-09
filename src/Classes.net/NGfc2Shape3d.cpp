#include "StdAfx.h"
#include "NGfc2Shape3d.h"
NGfc2Shape3d::NGfc2Shape3d()
{
    m_pEntity = new Gfc2Shape3d;
    m_bOwner = true;
}

NGfc2Shape3d::NGfc2Shape3d(void* pEntity, bool bOwner):
    NGfc2ParametricShape(pEntity, bOwner)
{
}

