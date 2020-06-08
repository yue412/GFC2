#ifndef NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "Gfc2SurfaceCurveSweptAreaSolidShape.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Surface.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SurfaceCurveSweptAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2SurfaceCurveSweptAreaSolidShape();
    NGfc2SurfaceCurveSweptAreaSolidShape(void* pEntity, bool bOwner);
    void setDirectrix(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix();
    bool hasDirectrix();
    NGfc2Curve3d^ getDirectrixPtr();
    void setReferenceSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceSurface();
    bool hasReferenceSurface();
    NGfc2Surface^ getReferenceSurfacePtr();

};
#endif
