#ifndef NGFC2POLYGON_H
#define NGFC2POLYGON_H

#include "NGfc2Topology.h"
#include "Gfc2Polygon.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Polygon: public NGfc2Topology
{
public:
    NGfc2Polygon();
    NGfc2Polygon(void* pEntity, bool bOwner);

};
#endif
