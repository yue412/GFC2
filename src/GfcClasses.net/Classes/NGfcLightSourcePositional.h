#ifndef NGFCLIGHTSOURCEPOSITIONAL_H
#define NGFCLIGHTSOURCEPOSITIONAL_H

#include "NGfcLightSource.h"
#include "GfcClasses\x3\GfcLightSourcePositional.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcLightSourcePositional: public NGfcLightSource
{
public:
    NGfcLightSourcePositional();
    NGfcLightSourcePositional(bool bNoCreate);
    void setPosition(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPosition();
    bool hasPosition();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setConstantAttenuation(NGfcDouble dValue);
    NGfcDouble getConstantAttenuation();
    bool hasConstantAttenuation();
    void setDistanceAttenuation(NGfcDouble dValue);
    NGfcDouble getDistanceAttenuation();
    bool hasDistanceAttenuation();
    void setQuadricAttenuation(NGfcDouble dValue);
    NGfcDouble getQuadricAttenuation();
    bool hasQuadricAttenuation();

};
#endif
