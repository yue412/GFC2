#ifndef NGFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define NGFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2CompositeCurve2dSweptSolidShape.h"
#include "NGfc2Curve2d.h"

public ref class NGfc2CompositeCurve2dSweptSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2CompositeCurve2dSweptSolidShape();
    NGfc2CompositeCurve2dSweptSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    int getSegmentsCount();
    void clearSegments();
    void addSegments(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSegments(int nIndex);

};
#endif
