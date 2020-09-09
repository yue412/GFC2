#ifndef GFC2BUILDING_H
#define GFC2BUILDING_H

#include "GfcClasses.h"
#include "Gfc2SpatialStructureElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Building: public Gfc2SpatialStructureElement
{
GFCENGINE_DEC_OBJECT(Gfc2Building, gfc::engine::CEntity)
public:
    Gfc2Building();
    Gfc2Building(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
