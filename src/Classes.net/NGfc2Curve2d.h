#ifndef NGFC2CURVE2D_H
#define NGFC2CURVE2D_H

#include "NGfc2Geometry.h"
#include "Gfc2Curve2d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Curve2d: public NGfc2Geometry
{
public:
    NGfc2Curve2d();
    NGfc2Curve2d(void* pEntity, bool bOwner);

};
#endif
