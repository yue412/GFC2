#ifndef NGFC2LIGHTSOURCE_H
#define NGFC2LIGHTSOURCE_H

#include "NGfc2RepresentationItem.h"
#include "GfcClasses\x3\Gfc2LightSource.h"
#include "NGfc2Color.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2LightSource: public NGfc2RepresentationItem
{
public:
    NGfc2LightSource();
    NGfc2LightSource(gfc::engine::CEntity* pEntity, bool bOwner);
    void setName(NGfc2Label sValue);
    NGfc2Label getName();
    bool hasName();
    void setLightColour(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLightColour();
    bool hasLightColour();
    void setAmbientIntensity(NGfc2Double dValue);
    NGfc2Double getAmbientIntensity();
    bool hasAmbientIntensity();
    void setIntensity(NGfc2Double dValue);
    NGfc2Double getIntensity();
    bool hasIntensity();

};
#endif
