#ifndef GFC2ELLIPSE3D_H
#define GFC2ELLIPSE3D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2PlaneCurve3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Ellipse3d: public Gfc2PlaneCurve3d
{
GFCENGINE_DEC_OBJECT(Gfc2Ellipse3d,gfc2::engine::EntityFactory)
public:
    Gfc2Ellipse3d();
    Gfc2Ellipse3d(bool bSetSchema);

};
#endif
