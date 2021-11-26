#ifndef NGFC2SPHERE_H
#define NGFC2SPHERE_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Sphere.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2Sphere: public NGfc2Surface
{
public:
    NGfc2Sphere();
    NGfc2Sphere(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setCoords(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoords();
    bool hasCoords();
    void setRangeU(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeU();
    bool hasRangeU();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();

};
#endif
