#include "StdAfx.h"
#include "NGfc2RepresentationItem.h"
NGfc2RepresentationItem::NGfc2RepresentationItem()
{
    m_pEntity = new Gfc2RepresentationItem;
    m_bOwner = true;
}

NGfc2RepresentationItem::NGfc2RepresentationItem(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

