#ifndef NGFC2ARC3D_H
#define NGFC2ARC3D_H

#include "NGfc2PlaneCurve3d.h"
#include "Gfc2Arc3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Arc3d: public NGfc2PlaneCurve3d
{
public:
    NGfc2Arc3d();
    NGfc2Arc3d(void* pEntity, bool bOwner);

};
#endif
