#ifndef GFCBUILDING_H
#define GFCBUILDING_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSpatialStructureElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBuilding: public GfcSpatialStructureElement
{
GFCENGINE_DEC_OBJECT(GfcBuilding, gfc::engine::CEntity)
public:
    GfcBuilding();
    GfcBuilding(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
