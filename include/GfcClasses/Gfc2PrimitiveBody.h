#ifndef GFC2PRIMITIVEBODY_H
#define GFC2PRIMITIVEBODY_H

#include "GfcClasses.h"
#include "Gfc2Body.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PrimitiveBody: public Gfc2Body
{
GFCENGINE_DEC_OBJECT(Gfc2PrimitiveBody, gfc::engine::CEntity)
public:
    Gfc2PrimitiveBody();
    Gfc2PrimitiveBody(bool bSetSchema);

};
#endif
