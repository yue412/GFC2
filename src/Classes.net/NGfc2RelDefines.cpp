#include "StdAfx.h"
#include "NGfc2RelDefines.h"
NGfc2RelDefines::NGfc2RelDefines()
{
    m_pEntity = new Gfc2RelDefines;
    m_bOwner = true;
}

NGfc2RelDefines::NGfc2RelDefines(void* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

