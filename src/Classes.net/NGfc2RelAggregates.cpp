#include "StdAfx.h"
#include "NGfc2RelAggregates.h"
NGfc2RelAggregates::NGfc2RelAggregates()
{
    m_pEntity = new Gfc2RelAggregates;
    m_bOwner = true;
}

NGfc2RelAggregates::NGfc2RelAggregates(void* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

