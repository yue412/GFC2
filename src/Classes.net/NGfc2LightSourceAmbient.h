#ifndef NGFC2LIGHTSOURCEAMBIENT_H
#define NGFC2LIGHTSOURCEAMBIENT_H

#include "NGfc2LightSource.h"
#include "Gfc2LightSourceAmbient.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LightSourceAmbient: public NGfc2LightSource
{
public:
    NGfc2LightSourceAmbient();
    NGfc2LightSourceAmbient(void* pEntity, bool bOwner);

};
#endif
