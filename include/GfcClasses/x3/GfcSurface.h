#ifndef GFCSURFACE_H
#define GFCSURFACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSurface: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcSurface, gfc::engine::CEntity)
public:
    GfcSurface();
    GfcSurface(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
