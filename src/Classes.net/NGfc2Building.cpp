#include "NGfc2Building.h"

using namespace gfc::classes::x3;

NGfc2Building::NGfc2Building()
{
    m_pEntity = new Gfc2Building;
    m_bOwner = true;
}

NGfc2Building::NGfc2Building(void* pEntity, bool bOwner):
    NGfc2SpatialStructureElement(pEntity, bOwner)
{
}

