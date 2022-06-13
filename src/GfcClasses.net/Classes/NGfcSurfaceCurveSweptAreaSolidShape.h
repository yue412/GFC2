#ifndef NGFCSURFACECURVESWEPTAREASOLIDSHAPE_H
#define NGFCSURFACECURVESWEPTAREASOLIDSHAPE_H

#include "NGfcSweptAreaSolidShape.h"
#include "GfcClasses\x3\GfcSurfaceCurveSweptAreaSolidShape.h"
#include "NGfcCurve3d.h"
#include "NGfcSurface.h"

public ref class NGfcSurfaceCurveSweptAreaSolidShape: public NGfcSweptAreaSolidShape
{
public:
    NGfcSurfaceCurveSweptAreaSolidShape();
    NGfcSurfaceCurveSweptAreaSolidShape(bool bNoCreate);
    void setDirectrix(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix();
    bool hasDirectrix();
    void setReferenceSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceSurface();
    bool hasReferenceSurface();

};
#endif
