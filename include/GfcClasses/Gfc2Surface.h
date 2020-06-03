#ifndef GFC2SURFACE_H
#define GFC2SURFACE_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Surface: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Surface, gfc::engine::Entity)
public:
    Gfc2Surface();
    Gfc2Surface(bool bSetSchema);

};
#endif
