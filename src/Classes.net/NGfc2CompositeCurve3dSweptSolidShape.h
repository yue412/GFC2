#ifndef NGFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define NGFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2CompositeCurve3dSweptSolidShape.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Surface.h"

public ref class NGfc2CompositeCurve3dSweptSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2CompositeCurve3dSweptSolidShape();
    NGfc2CompositeCurve3dSweptSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    int getSegmentsCount();
    void clearSegments();
    void addSegments(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSegments(int nIndex);
    int getReferencesCount();
    void clearReferences();
    void addReferences(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferences(int nIndex);

};
#endif
