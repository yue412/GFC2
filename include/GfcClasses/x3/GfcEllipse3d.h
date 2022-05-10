#ifndef GFCELLIPSE3D_H
#define GFCELLIPSE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPlaneCurve3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEllipse3d: public GfcPlaneCurve3d
{
GFCENGINE_DEC_OBJECT(GfcEllipse3d, gfc::engine::CEntity)
public:
    GfcEllipse3d();
    GfcEllipse3d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
