#ifndef GFC2POLYGON_H
#define GFC2POLYGON_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Polygon: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2Polygon, gfc::engine::Entity)
public:
    Gfc2Polygon();
    Gfc2Polygon(bool bSetSchema);

};
#endif
