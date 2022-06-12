#ifndef NGFCPRIMITIVEBODY_H
#define NGFCPRIMITIVEBODY_H

#include "NGfcBody.h"
#include "GfcClasses\x3\GfcPrimitiveBody.h"

public ref class NGfcPrimitiveBody: public NGfcBody
{
public:
    NGfcPrimitiveBody();
    NGfcPrimitiveBody(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
