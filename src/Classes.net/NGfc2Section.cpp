#include "StdAfx.h"
#include "NGfc2Section.h"
NGfc2Section::NGfc2Section()
{
    m_pEntity = new Gfc2Section;
    m_bOwner = true;
}

NGfc2Section::NGfc2Section(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

