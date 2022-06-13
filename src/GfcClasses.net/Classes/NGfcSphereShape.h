#ifndef NGFCSPHERESHAPE_H
#define NGFCSPHERESHAPE_H

#include "NGfcPrimitiveShape.h"
#include "GfcClasses\x3\GfcSphereShape.h"
#include "NTypeDef.h"

public ref class NGfcSphereShape: public NGfcPrimitiveShape
{
public:
    NGfcSphereShape();
    NGfcSphereShape(bool bNoCreate);
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();

};
#endif
