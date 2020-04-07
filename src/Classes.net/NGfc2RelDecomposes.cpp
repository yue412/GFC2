#include "StdAfx.h"
#include "NGfc2RelDecomposes.h"
NGfc2RelDecomposes::NGfc2RelDecomposes()
{
    m_pEntity = new Gfc2RelDecomposes;
    m_bOwner = true;
}

NGfc2RelDecomposes::NGfc2RelDecomposes(void* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

