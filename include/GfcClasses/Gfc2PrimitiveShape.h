#ifndef GFC2PRIMITIVESHAPE_H
#define GFC2PRIMITIVESHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PrimitiveShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2PrimitiveShape, gfc2::engine::Entity)
public:
    Gfc2PrimitiveShape();
    Gfc2PrimitiveShape(bool bSetSchema);

};
#endif
