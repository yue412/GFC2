#ifndef NGFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H
#define NGFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H

#include "NGfc2RevolvedAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2RevolvedAreaSolidTaperedShape.h"
#include "NGfc2Section.h"

public ref class NGfc2RevolvedAreaSolidTaperedShape: public NGfc2RevolvedAreaSolidShape
{
public:
    NGfc2RevolvedAreaSolidTaperedShape();
    NGfc2RevolvedAreaSolidTaperedShape(void* pEntity, bool bOwner);
    void setEndSweptArea(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndSweptArea();
    bool hasEndSweptArea();

};
#endif
