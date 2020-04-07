#include "StdAfx.h"
#include "NGfc2BooleanResult.h"
NGfc2BooleanResult::NGfc2BooleanResult()
{
    m_pEntity = new Gfc2BooleanResult;
    m_bOwner = true;
}

NGfc2BooleanResult::NGfc2BooleanResult(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

