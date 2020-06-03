#ifndef GFC2SITE_H
#define GFC2SITE_H

#include "GfcClasses.h"
#include "Gfc2SpatialStructureElement.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Site: public Gfc2SpatialStructureElement
{
GFCENGINE_DEC_OBJECT(Gfc2Site, gfc2::engine::Entity)
public:
    Gfc2Site();
    Gfc2Site(bool bSetSchema);

};
#endif
