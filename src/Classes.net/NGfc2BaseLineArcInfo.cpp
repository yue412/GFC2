#include "StdAfx.h"
#include "NGfc2BaseLineArcInfo.h"
NGfc2BaseLineArcInfo::NGfc2BaseLineArcInfo()
{
    m_pEntity = new Gfc2BaseLineArcInfo;
    m_bOwner = true;
}

NGfc2BaseLineArcInfo::NGfc2BaseLineArcInfo(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

