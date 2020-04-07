#ifndef NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define NGFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "Gfc2SurfaceCurveSweptAreaSolidShape.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Surface.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SurfaceCurveSweptAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2SurfaceCurveSweptAreaSolidShape();
    NGfc2SurfaceCurveSweptAreaSolidShape(void* pEntity, bool bOwner);
    void setDirectrix(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirectrix();
    bool hasDirectrix();
    NGfc2Curve3d^ getDirectrixPtr();
    void setReferenceSurface(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getReferenceSurface();
    bool hasReferenceSurface();
    NGfc2Surface^ getReferenceSurfacePtr();

};
#endif
