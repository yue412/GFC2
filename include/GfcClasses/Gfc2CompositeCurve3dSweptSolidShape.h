#ifndef GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CompositeCurve3dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2CompositeCurve3dSweptSolidShape,gfc2::engine::EntityFactory)
public:
    Gfc2CompositeCurve3dSweptSolidShape();
    Gfc2CompositeCurve3dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSegments(int nIndex) const;
    std::shared_ptr<Gfc2Curve3d> getSegmentsPtr(int nIndex);
    int getReferencesCount() const;
    void clearReferences();
    void addReferences(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getReferences(int nIndex) const;
    std::shared_ptr<Gfc2Surface> getReferencesPtr(int nIndex);

};
#endif
