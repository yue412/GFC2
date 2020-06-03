#ifndef GFC2LIGHTSOURCEAMBIENT_H
#define GFC2LIGHTSOURCEAMBIENT_H

#include "GfcClasses.h"
#include "Gfc2LightSource.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2LightSourceAmbient: public Gfc2LightSource
{
GFCENGINE_DEC_OBJECT(Gfc2LightSourceAmbient, gfc::engine::Entity)
public:
    Gfc2LightSourceAmbient();
    Gfc2LightSourceAmbient(bool bSetSchema);

};
#endif
