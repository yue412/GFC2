#ifndef GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SurfaceCurveSweptAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2SurfaceCurveSweptAreaSolidShape, gfc::engine::CEntity)
public:
    Gfc2SurfaceCurveSweptAreaSolidShape();
    Gfc2SurfaceCurveSweptAreaSolidShape(bool bSetSchema);
    void setDirectrix(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix() const;
    bool hasDirectrix() const;
    std::shared_ptr<Gfc2Curve3d> getDirectrixPtr();
    void setReferenceSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferenceSurface() const;
    bool hasReferenceSurface() const;
    std::shared_ptr<Gfc2Surface> getReferenceSurfacePtr();

};
#endif
