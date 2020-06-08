#ifndef NGFC2SWEPTAREASOLIDSHAPE_H
#define NGFC2SWEPTAREASOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "NGfc2Section.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SweptAreaSolidShape: public NGfc2SolidShape
{
public:
    NGfc2SweptAreaSolidShape();
    NGfc2SweptAreaSolidShape(void* pEntity, bool bOwner);
    void setSweptArea(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSweptArea();
    bool hasSweptArea();
    NGfc2Section^ getSweptAreaPtr();

};
#endif
