#include "StdAfx.h"
#include "NGfc2RelNests.h"
NGfc2RelNests::NGfc2RelNests()
{
    m_pEntity = new Gfc2RelNests;
    m_bOwner = true;
}

NGfc2RelNests::NGfc2RelNests(void* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

