#ifndef NGFC2PRIMITIVESHAPE_H
#define NGFC2PRIMITIVESHAPE_H

#include "NGfc2SolidShape.h"
#include "GfcClasses\x3\Gfc2PrimitiveShape.h"

public ref class NGfc2PrimitiveShape: public NGfc2SolidShape
{
public:
    NGfc2PrimitiveShape();
    NGfc2PrimitiveShape(void* pEntity, bool bOwner);

};
#endif
