#ifndef GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CompositeCurve3dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2CompositeCurve3dSweptSolidShape, gfc::engine::CEntity)
public:
    Gfc2CompositeCurve3dSweptSolidShape();
    Gfc2CompositeCurve3dSweptSolidShape(bool bSetSchema);
    int getSegmentsCount() const;
    void clearSegments();
    void addSegments(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSegments(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve3d> getSegmentsPtr(int nIndex);
    int getReferencesCount() const;
    void clearReferences();
    void addReferences(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferences(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Surface> getReferencesPtr(int nIndex);

};
#endif
