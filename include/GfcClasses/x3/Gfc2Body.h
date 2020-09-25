#ifndef GFC2BODY_H
#define GFC2BODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Body: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Body, gfc::engine::CEntity)
public:
    Gfc2Body();
    Gfc2Body(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
