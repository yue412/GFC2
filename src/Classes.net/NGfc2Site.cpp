#include "StdAfx.h"
#include "NGfc2Site.h"
NGfc2Site::NGfc2Site()
{
    m_pEntity = new Gfc2Site;
    m_bOwner = true;
}

NGfc2Site::NGfc2Site(void* pEntity, bool bOwner):
    NGfc2SpatialStructureElement(pEntity, bOwner)
{
}

