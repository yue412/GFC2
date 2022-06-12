#include "NGfcSpatialStructureElement.h"

using namespace gfc::classes::x3;

NGfcSpatialStructureElement::NGfcSpatialStructureElement()
{
    m_pEntity = new GfcSpatialStructureElement;
    m_bOwner = true;
}

NGfcSpatialStructureElement::NGfcSpatialStructureElement(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcObject(pEntity, bOwner)
{
}

