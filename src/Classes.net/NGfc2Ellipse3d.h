#ifndef NGFC2ELLIPSE3D_H
#define NGFC2ELLIPSE3D_H

#include "NGfc2PlaneCurve3d.h"
#include "GfcClasses\x3\Gfc2Ellipse3d.h"

public ref class NGfc2Ellipse3d: public NGfc2PlaneCurve3d
{
public:
    NGfc2Ellipse3d();
    NGfc2Ellipse3d(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
