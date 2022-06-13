#include "NGfcBuilding.h"

using namespace gfc::classes::x3;

NGfcBuilding::NGfcBuilding()
{
    m_pEntity = new GfcBuilding;
    m_bOwner = true;
}

NGfcBuilding::NGfcBuilding(bool bNoCreate):
    NGfcSpatialStructureElement(bNoCreate)
{
}

