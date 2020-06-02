#ifndef GFC2CURVE3D_H
#define GFC2CURVE3D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Curve3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Curve3d,gfc2::engine::EntityFactory)
public:
    Gfc2Curve3d();
    Gfc2Curve3d(bool bSetSchema);

};
#endif
