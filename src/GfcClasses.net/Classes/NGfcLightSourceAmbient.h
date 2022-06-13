#ifndef NGFCLIGHTSOURCEAMBIENT_H
#define NGFCLIGHTSOURCEAMBIENT_H

#include "NGfcLightSource.h"
#include "GfcClasses\x3\GfcLightSourceAmbient.h"

public ref class NGfcLightSourceAmbient: public NGfcLightSource
{
public:
    NGfcLightSourceAmbient();
    NGfcLightSourceAmbient(bool bNoCreate);

};
#endif
