#ifndef GFC2CURVE2D_H
#define GFC2CURVE2D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Curve2d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Curve2d, gfc2::engine::Entity)
public:
    Gfc2Curve2d();
    Gfc2Curve2d(bool bSetSchema);

};
#endif
