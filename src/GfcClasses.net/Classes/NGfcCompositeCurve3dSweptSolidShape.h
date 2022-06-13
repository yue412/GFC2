#ifndef NGFCCOMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define NGFCCOMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "NGfcSweptAreaSolidShape.h"
#include "GfcClasses\x3\GfcCompositeCurve3dSweptSolidShape.h"
#include "NGfcCurve3d.h"
#include "NGfcSurface.h"

public ref class NGfcCompositeCurve3dSweptSolidShape: public NGfcSweptAreaSolidShape
{
public:
    NGfcCompositeCurve3dSweptSolidShape();
    NGfcCompositeCurve3dSweptSolidShape(bool bNoCreate);
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
