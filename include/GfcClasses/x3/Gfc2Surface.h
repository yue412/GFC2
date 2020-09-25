#ifndef GFC2SURFACE_H
#define GFC2SURFACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Surface: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Surface, gfc::engine::CEntity)
public:
    Gfc2Surface();
    Gfc2Surface(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
