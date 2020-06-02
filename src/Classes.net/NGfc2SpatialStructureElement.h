#ifndef NGFC2SPATIALSTRUCTUREELEMENT_H
#define NGFC2SPATIALSTRUCTUREELEMENT_H

#include "NGfc2Object.h"
#include "Gfc2SpatialStructureElement.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SpatialStructureElement: public NGfc2Object
{
public:
    NGfc2SpatialStructureElement();
    NGfc2SpatialStructureElement(void* pEntity, bool bOwner);

};
#endif
