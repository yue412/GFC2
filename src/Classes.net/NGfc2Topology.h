#ifndef NGFC2TOPOLOGY_H
#define NGFC2TOPOLOGY_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Topology.h"

public ref class NGfc2Topology: public NGfc2Geometry
{
public:
    NGfc2Topology();
    NGfc2Topology(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
