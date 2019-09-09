#ifndef NGFC2SURFACE_H
#define NGFC2SURFACE_H

#include "NGfc2Geometry.h"
#include "Gfc2Surface.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Surface: public NGfc2Geometry
{
public:
    NGfc2Surface();
    NGfc2Surface(void* pEntity, bool bOwner);

};
#endif
