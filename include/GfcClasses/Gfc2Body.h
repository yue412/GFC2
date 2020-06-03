#ifndef GFC2BODY_H
#define GFC2BODY_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Body: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Body, gfc2::engine::Entity)
public:
    Gfc2Body();
    Gfc2Body(bool bSetSchema);

};
#endif
