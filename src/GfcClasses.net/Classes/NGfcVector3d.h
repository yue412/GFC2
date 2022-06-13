#ifndef NGFCVECTOR3D_H
#define NGFCVECTOR3D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcVector3d: public NGfcGeometry
{
public:
    NGfcVector3d();
    NGfcVector3d(bool bNoCreate);
    void setX(NGfcDouble dValue);
    NGfcDouble getX();
    bool hasX();
    void setY(NGfcDouble dValue);
    NGfcDouble getY();
    bool hasY();
    void setZ(NGfcDouble dValue);
    NGfcDouble getZ();
    bool hasZ();

};
#endif
