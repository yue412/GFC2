#ifndef GFC2GEOMETRY_H
#define GFC2GEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Geometry: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2Geometry, gfc::engine::CEntity)
public:
    Gfc2Geometry();
    Gfc2Geometry(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
