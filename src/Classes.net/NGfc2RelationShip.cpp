#include "StdAfx.h"
#include "NGfc2RelationShip.h"
NGfc2RelationShip::NGfc2RelationShip()
{
    m_pEntity = new Gfc2RelationShip;
    m_bOwner = true;
}

NGfc2RelationShip::NGfc2RelationShip(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

