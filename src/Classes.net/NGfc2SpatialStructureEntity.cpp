#include "StdAfx.h"
#include "NGfc2SpatialStructureEntity.h"
NGfc2SpatialStructureEntity::NGfc2SpatialStructureEntity()
{
    m_pEntity = new Gfc2SpatialStructureEntity;
    m_bOwner = true;
}

NGfc2SpatialStructureEntity::NGfc2SpatialStructureEntity(void* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

