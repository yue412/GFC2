#ifndef GFC2ELLIPSE3D_H
#define GFC2ELLIPSE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2PlaneCurve3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Ellipse3d: public Gfc2PlaneCurve3d
{
GFCENGINE_DEC_OBJECT(Gfc2Ellipse3d, gfc::engine::CEntity)
public:
    Gfc2Ellipse3d();
    Gfc2Ellipse3d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
