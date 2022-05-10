#ifndef GFCSOLIDSHAPE_H
#define GFCSOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcParametricShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSolidShape: public GfcParametricShape
{
GFCENGINE_DEC_OBJECT(GfcSolidShape, gfc::engine::CEntity)
public:
    GfcSolidShape();
    GfcSolidShape(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
