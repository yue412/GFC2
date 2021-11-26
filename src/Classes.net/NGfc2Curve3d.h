#ifndef NGFC2CURVE3D_H
#define NGFC2CURVE3D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Curve3d.h"

public ref class NGfc2Curve3d: public NGfc2Geometry
{
public:
    NGfc2Curve3d();
    NGfc2Curve3d(void* pEntity, bool bOwner);

};
#endif
