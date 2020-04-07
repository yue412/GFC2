#ifndef NGFC2PRIMITIVESHAPE_H
#define NGFC2PRIMITIVESHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2PrimitiveShape.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PrimitiveShape: public NGfc2SolidShape
{
public:
    NGfc2PrimitiveShape();
    NGfc2PrimitiveShape(void* pEntity, bool bOwner);

};
#endif
