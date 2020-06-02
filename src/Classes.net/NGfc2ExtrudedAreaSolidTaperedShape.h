#ifndef NGFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define NGFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "NGfc2ExtrudedAreaSolidShape.h"
#include "Gfc2ExtrudedAreaSolidTaperedShape.h"
#include "NGfc2Section.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ExtrudedAreaSolidTaperedShape: public NGfc2ExtrudedAreaSolidShape
{
public:
    NGfc2ExtrudedAreaSolidTaperedShape();
    NGfc2ExtrudedAreaSolidTaperedShape(void* pEntity, bool bOwner);
    void setEndSweptArea(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getEndSweptArea();
    bool hasEndSweptArea();
    NGfc2Section^ getEndSweptAreaPtr();

};
#endif
