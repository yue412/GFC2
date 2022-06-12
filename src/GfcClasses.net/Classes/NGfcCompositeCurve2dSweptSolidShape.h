#ifndef NGFCCOMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define NGFCCOMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "NGfcSweptAreaSolidShape.h"
#include "GfcClasses\x3\GfcCompositeCurve2dSweptSolidShape.h"
#include "NGfcCurve2d.h"

public ref class NGfcCompositeCurve2dSweptSolidShape: public NGfcSweptAreaSolidShape
{
public:
    NGfcCompositeCurve2dSweptSolidShape();
    NGfcCompositeCurve2dSweptSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    int getSegmentsCount();
    void clearSegments();
    void addSegments(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSegments(int nIndex);

};
#endif
