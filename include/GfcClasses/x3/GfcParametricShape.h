#ifndef GFCPARAMETRICSHAPE_H
#define GFCPARAMETRICSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcParametricShape: public GfcShape
{
GFCENGINE_DEC_OBJECT(GfcParametricShape, gfc::engine::CEntity)
public:
    GfcParametricShape();
    GfcParametricShape(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
