#ifndef NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2SurfaceCurveSweptAreaSolidShape.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Surface.h"

public ref class NGfc2SurfaceCurveSweptAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2SurfaceCurveSweptAreaSolidShape();
    NGfc2SurfaceCurveSweptAreaSolidShape(void* pEntity, bool bOwner);
    void setDirectrix(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix();
    bool hasDirectrix();
    void setReferenceSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceSurface();
    bool hasReferenceSurface();

};
#endif
