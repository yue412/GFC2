#ifndef NGFCARC3D_H
#define NGFCARC3D_H

#include "NGfcPlaneCurve3d.h"
#include "GfcClasses\x3\GfcArc3d.h"

public ref class NGfcArc3d: public NGfcPlaneCurve3d
{
public:
    NGfcArc3d();
    NGfcArc3d(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
