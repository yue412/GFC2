#ifndef GFCARC3D_H
#define GFCARC3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcPlaneCurve3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcArc3d: public GfcPlaneCurve3d
{
GFCENGINE_DEC_OBJECT(GfcArc3d, gfc::engine::CEntity)
public:
    GfcArc3d();
    GfcArc3d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
