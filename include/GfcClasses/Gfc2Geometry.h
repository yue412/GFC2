#ifndef GFC2GEOMETRY_H
#define GFC2GEOMETRY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Geometry: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Geometry,gfc2::engine::EntityFactory)
public:
    Gfc2Geometry();
    Gfc2Geometry(bool bSetSchema);

};
#endif
