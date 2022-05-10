#ifndef GFCSURFACECURVESWEPTAREASOLIDSHAPE_H
#define GFCSURFACECURVESWEPTAREASOLIDSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSweptAreaSolidShape.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSurfaceCurveSweptAreaSolidShape: public GfcSweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcSurfaceCurveSweptAreaSolidShape, gfc::engine::CEntity)
public:
    GfcSurfaceCurveSweptAreaSolidShape();
    GfcSurfaceCurveSweptAreaSolidShape(bool bSetSchema);
    void setDirectrix(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix() const;
    bool hasDirectrix() const;
    std::shared_ptr<GfcCurve3d> getDirectrixPtr();
    void setReferenceSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferenceSurface() const;
    bool hasReferenceSurface() const;
    std::shared_ptr<GfcSurface> getReferenceSurfacePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
