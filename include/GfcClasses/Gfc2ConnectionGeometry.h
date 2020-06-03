#ifndef GFC2CONNECTIONGEOMETRY_H
#define GFC2CONNECTIONGEOMETRY_H

#include "GfcClasses.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ConnectionGeometry: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionGeometry, gfc::engine::Entity)
public:
    Gfc2ConnectionGeometry();
    Gfc2ConnectionGeometry(bool bSetSchema);

};
#endif
