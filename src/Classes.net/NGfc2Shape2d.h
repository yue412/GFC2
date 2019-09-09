#ifndef NGFC2SHAPE2D_H
#define NGFC2SHAPE2D_H

#include "NGfc2ParametricShape.h"
#include "Gfc2Shape2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Shape2d: public NGfc2ParametricShape
{
public:
    NGfc2Shape2d();
    NGfc2Shape2d(void* pEntity, bool bOwner);
    void setElev(NGfc2Double dValue);
    NGfc2Double getElev();
    bool hasElev();

};
#endif
