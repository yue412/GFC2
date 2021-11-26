#ifndef NGFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define NGFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "NGfc2ExtrudedAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2ExtrudedAreaSolidTaperedShape.h"
#include "NGfc2Section.h"

public ref class NGfc2ExtrudedAreaSolidTaperedShape: public NGfc2ExtrudedAreaSolidShape
{
public:
    NGfc2ExtrudedAreaSolidTaperedShape();
    NGfc2ExtrudedAreaSolidTaperedShape(void* pEntity, bool bOwner);
    void setEndSweptArea(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndSweptArea();
    bool hasEndSweptArea();

};
#endif
