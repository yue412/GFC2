#ifndef GFCCURVE2D_H
#define GFCCURVE2D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCurve2d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcCurve2d, gfc::engine::CEntity)
public:
    GfcCurve2d();
    GfcCurve2d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
