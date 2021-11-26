#ifndef NGFC2PARAMETRICSHAPE_H
#define NGFC2PARAMETRICSHAPE_H

#include "NGfc2Shape.h"
#include "GfcClasses\x3\Gfc2ParametricShape.h"

public ref class NGfc2ParametricShape: public NGfc2Shape
{
public:
    NGfc2ParametricShape();
    NGfc2ParametricShape(void* pEntity, bool bOwner);

};
#endif
