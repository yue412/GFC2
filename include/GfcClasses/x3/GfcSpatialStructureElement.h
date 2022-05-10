#ifndef GFCSPATIALSTRUCTUREELEMENT_H
#define GFCSPATIALSTRUCTUREELEMENT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSpatialStructureElement: public GfcObject
{
GFCENGINE_DEC_OBJECT(GfcSpatialStructureElement, gfc::engine::CEntity)
public:
    GfcSpatialStructureElement();
    GfcSpatialStructureElement(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
