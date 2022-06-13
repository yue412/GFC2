#include "NGfcSpatialStructureElement.h"

using namespace gfc::classes::x3;

NGfcSpatialStructureElement::NGfcSpatialStructureElement()
{
    m_pEntity = new GfcSpatialStructureElement;
    m_bOwner = true;
}

NGfcSpatialStructureElement::NGfcSpatialStructureElement(bool bNoCreate):
    NGfcObject(bNoCreate)
{
}

