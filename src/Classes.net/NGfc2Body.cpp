#include "StdAfx.h"
#include "NGfc2Body.h"
NGfc2Body::NGfc2Body()
{
    m_pEntity = new Gfc2Body;
    m_bOwner = true;
}

NGfc2Body::NGfc2Body(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

