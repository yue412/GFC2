#ifndef NGFC2SPHERE_H
#define NGFC2SPHERE_H

#include "NGfc2Surface.h"
#include "Gfc2Sphere.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Sphere: public NGfc2Surface
{
public:
    NGfc2Sphere();
    NGfc2Sphere(void* pEntity, bool bOwner);
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setCoords(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoords();
    bool hasCoords();
    NGfc2Coordinates3d^ getCoordsPtr();
    void setRangeU(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeU();
    bool hasRangeU();
    NGfc2Intervald^ getRangeUPtr();
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();

};
#endif
