#ifndef NGFC2PRIMITIVEBODY_H
#define NGFC2PRIMITIVEBODY_H

#include "NGfc2Body.h"
#include "Gfc2PrimitiveBody.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PrimitiveBody: public NGfc2Body
{
public:
    NGfc2PrimitiveBody();
    NGfc2PrimitiveBody(void* pEntity, bool bOwner);

};
#endif
