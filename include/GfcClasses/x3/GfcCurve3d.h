#ifndef GFCCURVE3D_H
#define GFCCURVE3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCurve3d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcCurve3d, gfc::engine::CEntity)
public:
    GfcCurve3d();
    GfcCurve3d(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
