#ifndef GFCSITE_H
#define GFCSITE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSpatialStructureElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSite: public GfcSpatialStructureElement
{
GFCENGINE_DEC_OBJECT(GfcSite, gfc::engine::CEntity)
public:
    GfcSite();
    GfcSite(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
