#ifndef GFCCOMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define GFCCOMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSweptAreaSolidShape.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCompositeCurve2dSweptSolidShape: public GfcSweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcCompositeCurve2dSweptSolidShape, gfc::engine::CEntity)
public:
    GfcCompositeCurve2dSweptSolidShape();
    GfcCompositeCurve2dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSegments(int nIndex) const;
    std::shared_ptr<GfcCurve2d> getSegmentsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
