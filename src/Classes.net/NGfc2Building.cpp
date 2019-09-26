#include "StdAfx.h"
#include "NGfc2Building.h"
NGfc2Building::NGfc2Building()
{
    m_pEntity = new Gfc2Building;
    m_bOwner = true;
}

NGfc2Building::NGfc2Building(void* pEntity, bool bOwner):
    NGfc2SpatialStructureEntity(pEntity, bOwner)
{
}

