#ifndef GFC2GEOMETRY_H
#define GFC2GEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Geometry: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Geometry, gfc::engine::CEntity)
public:
    Gfc2Geometry();
    Gfc2Geometry(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
