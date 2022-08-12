#ifndef GFCCONNECTIONGEOMETRY_H
#define GFCCONNECTIONGEOMETRY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConnectionGeometry: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcConnectionGeometry, gfc::engine::CEntity)
public:
    GfcConnectionGeometry();
    GfcConnectionGeometry(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
