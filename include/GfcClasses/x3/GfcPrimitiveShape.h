#ifndef GFCPRIMITIVESHAPE_H
#define GFCPRIMITIVESHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPrimitiveShape: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcPrimitiveShape, gfc::engine::CEntity)
public:
    GfcPrimitiveShape();
    GfcPrimitiveShape(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
