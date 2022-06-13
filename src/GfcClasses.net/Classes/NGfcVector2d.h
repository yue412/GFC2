#ifndef NGFCVECTOR2D_H
#define NGFCVECTOR2D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcVector2d: public NGfcGeometry
{
public:
    NGfcVector2d();
    NGfcVector2d(bool bNoCreate);
    void setX(NGfcDouble dValue);
    NGfcDouble getX();
    bool hasX();
    void setY(NGfcDouble dValue);
    NGfcDouble getY();
    bool hasY();

};
#endif
