#include "StdAfx.h"
#include "NGfc2ConnectionGeometry.h"
NGfc2ConnectionGeometry::NGfc2ConnectionGeometry()
{
    m_pEntity = new Gfc2ConnectionGeometry;
    m_bOwner = true;
}

NGfc2ConnectionGeometry::NGfc2ConnectionGeometry(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

