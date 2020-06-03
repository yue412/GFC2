#ifndef GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve2d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CompositeCurve2dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2CompositeCurve2dSweptSolidShape, gfc2::engine::Entity)
public:
    Gfc2CompositeCurve2dSweptSolidShape();
    Gfc2CompositeCurve2dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSegments(int nIndex) const;
    std::shared_ptr<Gfc2Curve2d> getSegmentsPtr(int nIndex);

};
#endif
