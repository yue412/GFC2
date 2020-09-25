#ifndef GFC2CURVE2D_H
#define GFC2CURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Curve2d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Curve2d, gfc::engine::CEntity)
public:
    Gfc2Curve2d();
    Gfc2Curve2d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
