#ifndef GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SweptAreaSolidShape.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CompositeCurve2dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2CompositeCurve2dSweptSolidShape, gfc::engine::CEntity)
public:
    Gfc2CompositeCurve2dSweptSolidShape();
    Gfc2CompositeCurve2dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSegments(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve2d> getSegmentsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
