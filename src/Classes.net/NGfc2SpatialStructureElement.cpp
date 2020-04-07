#include "StdAfx.h"
#include "NGfc2SpatialStructureElement.h"
NGfc2SpatialStructureElement::NGfc2SpatialStructureElement()
{
    m_pEntity = new Gfc2SpatialStructureElement;
    m_bOwner = true;
}

NGfc2SpatialStructureElement::NGfc2SpatialStructureElement(void* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

