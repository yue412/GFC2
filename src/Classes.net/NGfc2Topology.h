#ifndef NGFC2TOPOLOGY_H
#define NGFC2TOPOLOGY_H

#include "NGfc2Geometry.h"
#include "Gfc2Topology.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Topology: public NGfc2Geometry
{
public:
    NGfc2Topology();
    NGfc2Topology(void* pEntity, bool bOwner);

};
#endif
