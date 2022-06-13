#ifndef NGFCRULEDSURFACE_H
#define NGFCRULEDSURFACE_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcRuledSurface.h"
#include "NGfcIntervald.h"
#include "NGfcCurve3d.h"
#include "NTypeDef.h"

public ref class NGfcRuledSurface: public NGfcSurface
{
public:
    NGfcRuledSurface();
    NGfcRuledSurface(bool bNoCreate);
    void setApexIndex(NGfcInteger nValue);
    NGfcInteger getApexIndex();
    bool hasApexIndex();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setRangeU(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeU();
    bool hasRangeU();
    void setDirectrix1(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix1();
    bool hasDirectrix1();
    void setDirectrix2(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix2();
    bool hasDirectrix2();

};
#endif
