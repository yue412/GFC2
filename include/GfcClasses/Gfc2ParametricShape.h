#ifndef GFC2PARAMETRICSHAPE_H
#define GFC2PARAMETRICSHAPE_H

#include "GfcClasses.h"
#include "Gfc2Shape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ParametricShape: public Gfc2Shape
{
GFCENGINE_DEC_OBJECT(Gfc2ParametricShape, gfc::engine::Entity)
public:
    Gfc2ParametricShape();
    Gfc2ParametricShape(bool bSetSchema);

};
#endif
