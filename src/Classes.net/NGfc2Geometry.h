#ifndef NGFC2GEOMETRY_H
#define NGFC2GEOMETRY_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2Geometry.h"

public ref class NGfc2Geometry: public NGfc2Root
{
public:
    NGfc2Geometry();
    NGfc2Geometry(void* pEntity, bool bOwner);

};
#endif
