#ifndef NGFCLIGHTSOURCEDIRECTIONAL_H
#define NGFCLIGHTSOURCEDIRECTIONAL_H

#include "NGfcLightSource.h"
#include "GfcClasses\x3\GfcLightSourceDirectional.h"
#include "NGfcVector3d.h"

public ref class NGfcLightSourceDirectional: public NGfcLightSource
{
public:
    NGfcLightSourceDirectional();
    NGfcLightSourceDirectional(bool bNoCreate);
    void setOrientation(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOrientation();
    bool hasOrientation();

};
#endif
