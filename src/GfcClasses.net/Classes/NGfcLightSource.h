#ifndef NGFCLIGHTSOURCE_H
#define NGFCLIGHTSOURCE_H

#include "NGfcRepresentationItem.h"
#include "GfcClasses\x3\GfcLightSource.h"
#include "NGfcColor.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcLightSource: public NGfcRepresentationItem
{
public:
    NGfcLightSource();
    NGfcLightSource(bool bNoCreate);
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();
    void setLightColour(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLightColour();
    bool hasLightColour();
    void setAmbientIntensity(NGfcDouble dValue);
    NGfcDouble getAmbientIntensity();
    bool hasAmbientIntensity();
    void setIntensity(NGfcDouble dValue);
    NGfcDouble getIntensity();
    bool hasIntensity();

};
#endif
