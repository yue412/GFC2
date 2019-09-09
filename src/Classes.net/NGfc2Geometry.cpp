#include "StdAfx.h"
#include "NGfc2Geometry.h"
NGfc2Geometry::NGfc2Geometry()
{
    m_pEntity = new Gfc2Geometry;
    m_bOwner = true;
}

NGfc2Geometry::NGfc2Geometry(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

