#ifndef GFC2SOLIDSHAPE_H
#define GFC2SOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2ParametricShape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SolidShape: public Gfc2ParametricShape
{
GFCENGINE_DEC_OBJECT(Gfc2SolidShape, gfc2::engine::Entity)
public:
    Gfc2SolidShape();
    Gfc2SolidShape(bool bSetSchema);

};
#endif
