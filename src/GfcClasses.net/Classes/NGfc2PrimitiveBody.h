#ifndef NGFC2PRIMITIVEBODY_H
#define NGFC2PRIMITIVEBODY_H

#include "NGfc2Body.h"
#include "GfcClasses\x3\Gfc2PrimitiveBody.h"

public ref class NGfc2PrimitiveBody: public NGfc2Body
{
public:
    NGfc2PrimitiveBody();
    NGfc2PrimitiveBody(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
