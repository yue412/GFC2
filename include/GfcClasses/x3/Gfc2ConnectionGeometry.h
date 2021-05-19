#ifndef GFC2CONNECTIONGEOMETRY_H
#define GFC2CONNECTIONGEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ConnectionGeometry: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionGeometry, gfc::engine::CEntity)
public:
    Gfc2ConnectionGeometry();
    Gfc2ConnectionGeometry(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
