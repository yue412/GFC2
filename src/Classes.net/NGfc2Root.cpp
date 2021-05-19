#include "StdAfx.h"
#include "NGfc2Root.h"
NGfc2Root::NGfc2Root()
{
    m_pEntity = new Gfc2Root;
    m_bOwner = true;
}

NGfc2Root::NGfc2Root(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

