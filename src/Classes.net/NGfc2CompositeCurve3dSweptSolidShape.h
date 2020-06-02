#ifndef NGFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define NGFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "Gfc2CompositeCurve3dSweptSolidShape.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Surface.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CompositeCurve3dSweptSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2CompositeCurve3dSweptSolidShape();
    NGfc2CompositeCurve3dSweptSolidShape(void* pEntity, bool bOwner);
    int getSegmentsCount();
    void clearSegments();
    void addSegments(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSegments(int nIndex);
    NGfc2Curve3d^ getSegmentsPtr(int nIndex);
    int getReferencesCount();
    void clearReferences();
    void addReferences(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getReferences(int nIndex);
    NGfc2Surface^ getReferencesPtr(int nIndex);

};
#endif
