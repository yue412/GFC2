#include "StdAfx.h"
#include "NGfc2TwoPointAssitAxis.h"
NGfc2TwoPointAssitAxis::NGfc2TwoPointAssitAxis()
{
    m_pEntity = new Gfc2TwoPointAssitAxis;
    m_bOwner = true;
}

NGfc2TwoPointAssitAxis::NGfc2TwoPointAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

