#ifndef GFCPRIMITIVEBODY_H
#define GFCPRIMITIVEBODY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcBody.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPrimitiveBody: public GfcBody
{
GFCENGINE_DEC_OBJECT(GfcPrimitiveBody, gfc::engine::CEntity)
public:
    GfcPrimitiveBody();
    GfcPrimitiveBody(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
