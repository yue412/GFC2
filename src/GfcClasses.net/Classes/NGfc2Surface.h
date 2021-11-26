#ifndef NGFC2SURFACE_H
#define NGFC2SURFACE_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Surface.h"

public ref class NGfc2Surface: public NGfc2Geometry
{
public:
    NGfc2Surface();
    NGfc2Surface(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
