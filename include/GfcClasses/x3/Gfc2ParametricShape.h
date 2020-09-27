#ifndef GFC2PARAMETRICSHAPE_H
#define GFC2PARAMETRICSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Shape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ParametricShape: public Gfc2Shape
{
GFCENGINE_DEC_OBJECT(Gfc2ParametricShape, gfc::engine::CEntity)
public:
    Gfc2ParametricShape();
    Gfc2ParametricShape(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
