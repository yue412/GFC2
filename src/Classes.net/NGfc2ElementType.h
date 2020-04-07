#ifndef NGFC2ELEMENTTYPE_H
#define NGFC2ELEMENTTYPE_H

#include "NGfc2Object.h"
#include "Gfc2ElementType.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ElementType: public NGfc2Object
{
public:
    NGfc2ElementType();
    NGfc2ElementType(void* pEntity, bool bOwner);
    void setType(NGfc2Integer nValue);
    NGfc2Integer getType();
    bool hasType();

};
#endif
