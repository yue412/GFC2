#ifndef GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SurfaceCurveSweptAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2SurfaceCurveSweptAreaSolidShape,gfc2::engine::EntityFactory)
public:
    Gfc2SurfaceCurveSweptAreaSolidShape();
    Gfc2SurfaceCurveSweptAreaSolidShape(bool bSetSchema);
    void setDirectrix(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirectrix() const;
    bool hasDirectrix() const;
    std::shared_ptr<Gfc2Curve3d> getDirectrixPtr();
    void setReferenceSurface(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getReferenceSurface() const;
    bool hasReferenceSurface() const;
    std::shared_ptr<Gfc2Surface> getReferenceSurfacePtr();

};
#endif
