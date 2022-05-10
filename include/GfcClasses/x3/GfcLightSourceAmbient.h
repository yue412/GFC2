#ifndef GFCLIGHTSOURCEAMBIENT_H
#define GFCLIGHTSOURCEAMBIENT_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcLightSource.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLightSourceAmbient: public GfcLightSource
{
GFCENGINE_DEC_OBJECT(GfcLightSourceAmbient, gfc::engine::CEntity)
public:
    GfcLightSourceAmbient();
    GfcLightSourceAmbient(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
