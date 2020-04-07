#ifndef NGFC2LIGHTSOURCE_H
#define NGFC2LIGHTSOURCE_H

#include "NGfc2RepresentationItem.h"
#include "Gfc2LightSource.h"
#include "NGfc2Color.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LightSource: public NGfc2RepresentationItem
{
public:
    NGfc2LightSource();
    NGfc2LightSource(void* pEntity, bool bOwner);
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();
    void setLightColour(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLightColour();
    bool hasLightColour();
    NGfc2Color^ getLightColourPtr();
    void setAmbientIntensity(NGfc2Double dValue);
    NGfc2Double getAmbientIntensity();
    bool hasAmbientIntensity();
    void setIntensity(NGfc2Double dValue);
    NGfc2Double getIntensity();
    bool hasIntensity();

};
#endif
