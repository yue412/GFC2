#ifndef NGFCSWEPTAREASOLIDSHAPE_H
#define NGFCSWEPTAREASOLIDSHAPE_H

#include "NGfcSolidShape.h"
#include "GfcClasses\x3\GfcSweptAreaSolidShape.h"
#include "NGfcSection.h"

public ref class NGfcSweptAreaSolidShape: public NGfcSolidShape
{
public:
    NGfcSweptAreaSolidShape();
    NGfcSweptAreaSolidShape(bool bNoCreate);
    void setSweptArea(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSweptArea();
    bool hasSweptArea();

};
#endif
