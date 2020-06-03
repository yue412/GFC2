#ifndef GFC2GEOMETRY_H
#define GFC2GEOMETRY_H

#include "GfcClasses.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Geometry: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Geometry, gfc::engine::Entity)
public:
    Gfc2Geometry();
    Gfc2Geometry(bool bSetSchema);

};
#endif
