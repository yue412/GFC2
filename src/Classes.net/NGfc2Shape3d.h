#ifndef NGFC2SHAPE3D_H
#define NGFC2SHAPE3D_H

#include "NGfc2ParametricShape.h"
#include "Gfc2Shape3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Shape3d: public NGfc2ParametricShape
{
public:
    NGfc2Shape3d();
    NGfc2Shape3d(void* pEntity, bool bOwner);

};
#endif
