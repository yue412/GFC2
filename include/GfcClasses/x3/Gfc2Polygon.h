#ifndef GFC2POLYGON_H
#define GFC2POLYGON_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Topology.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Polygon: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2Polygon, gfc::engine::CEntity)
public:
    Gfc2Polygon();
    Gfc2Polygon(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
