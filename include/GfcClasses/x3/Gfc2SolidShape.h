#ifndef GFC2SOLIDSHAPE_H
#define GFC2SOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ParametricShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SolidShape: public Gfc2ParametricShape
{
GFCENGINE_DEC_OBJECT(Gfc2SolidShape, gfc::engine::CEntity)
public:
    Gfc2SolidShape();
    Gfc2SolidShape(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
