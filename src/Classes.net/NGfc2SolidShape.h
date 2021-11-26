#ifndef NGFC2SOLIDSHAPE_H
#define NGFC2SOLIDSHAPE_H

#include "NGfc2ParametricShape.h"
#include "GfcClasses\x3\Gfc2SolidShape.h"

public ref class NGfc2SolidShape: public NGfc2ParametricShape
{
public:
    NGfc2SolidShape();
    NGfc2SolidShape(void* pEntity, bool bOwner);

};
#endif
