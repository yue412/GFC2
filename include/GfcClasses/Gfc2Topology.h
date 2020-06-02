#ifndef GFC2TOPOLOGY_H
#define GFC2TOPOLOGY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Topology: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Topology,gfc2::engine::EntityFactory)
public:
    Gfc2Topology();
    Gfc2Topology(bool bSetSchema);

};
#endif
