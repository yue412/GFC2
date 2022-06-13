#ifndef NGFCSPHERE_H
#define NGFCSPHERE_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcSphere.h"
#include "NGfcCoordinates3d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcSphere: public NGfcSurface
{
public:
    NGfcSphere();
    NGfcSphere(bool bNoCreate);
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
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
