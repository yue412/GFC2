#ifndef NGFC2CURVE2D_H
#define NGFC2CURVE2D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Curve2d.h"

public ref class NGfc2Curve2d: public NGfc2Geometry
{
public:
    NGfc2Curve2d();
    NGfc2Curve2d(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
