#ifndef NGFCEXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define NGFCEXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "NGfcExtrudedAreaSolidShape.h"
#include "GfcClasses\x3\GfcExtrudedAreaSolidTaperedShape.h"
#include "NGfcSection.h"

public ref class NGfcExtrudedAreaSolidTaperedShape: public NGfcExtrudedAreaSolidShape
{
public:
    NGfcExtrudedAreaSolidTaperedShape();
    NGfcExtrudedAreaSolidTaperedShape(bool bNoCreate);
    void setEndSweptArea(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndSweptArea();
    bool hasEndSweptArea();

};
#endif
