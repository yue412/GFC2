#ifndef NGFCSIMPLEPOLYGON_H
#define NGFCSIMPLEPOLYGON_H

#include "NGfcPolygon.h"
#include "GfcClasses\x3\GfcSimplePolygon.h"
#include "NGfcSimpleLoop.h"

public ref class NGfcSimplePolygon: public NGfcPolygon
{
public:
    NGfcSimplePolygon();
    NGfcSimplePolygon(bool bNoCreate);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);

};
#endif
