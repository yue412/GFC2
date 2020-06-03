#ifndef GFC2ARC3D_H
#define GFC2ARC3D_H

#include "GfcClasses.h"
#include "Gfc2PlaneCurve3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Arc3d: public Gfc2PlaneCurve3d
{
GFCENGINE_DEC_OBJECT(Gfc2Arc3d, gfc::engine::Entity)
public:
    Gfc2Arc3d();
    Gfc2Arc3d(bool bSetSchema);

};
#endif
