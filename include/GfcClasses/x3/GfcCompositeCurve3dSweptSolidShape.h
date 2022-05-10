#ifndef GFCCOMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define GFCCOMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSweptAreaSolidShape.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCompositeCurve3dSweptSolidShape: public GfcSweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcCompositeCurve3dSweptSolidShape, gfc::engine::CEntity)
public:
    GfcCompositeCurve3dSweptSolidShape();
    GfcCompositeCurve3dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSegments(int nIndex) const;
    std::shared_ptr<GfcCurve3d> getSegmentsPtr(int nIndex);
    int getReferencesCount() const;
    void clearReferences();
    void addReferences(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferences(int nIndex) const;
    std::shared_ptr<GfcSurface> getReferencesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
