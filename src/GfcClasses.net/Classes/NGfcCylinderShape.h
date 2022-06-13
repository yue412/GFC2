#ifndef NGFCCYLINDERSHAPE_H
#define NGFCCYLINDERSHAPE_H

#include "NGfcPrimitiveShape.h"
#include "GfcClasses\x3\GfcCylinderShape.h"
#include "NTypeDef.h"

public ref class NGfcCylinderShape: public NGfcPrimitiveShape
{
public:
    NGfcCylinderShape();
    NGfcCylinderShape(bool bNoCreate);
    void setHeight(NGfcDouble dValue);
    NGfcDouble getHeight();
    bool hasHeight();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();

};
#endif
