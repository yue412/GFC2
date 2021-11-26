#ifndef NGFC2LIGHTSOURCEAMBIENT_H
#define NGFC2LIGHTSOURCEAMBIENT_H

#include "NGfc2LightSource.h"
#include "GfcClasses\x3\Gfc2LightSourceAmbient.h"

public ref class NGfc2LightSourceAmbient: public NGfc2LightSource
{
public:
    NGfc2LightSourceAmbient();
    NGfc2LightSourceAmbient(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
