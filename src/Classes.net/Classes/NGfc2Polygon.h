#ifndef NGFC2POLYGON_H
#define NGFC2POLYGON_H

#include "NGfc2Topology.h"
#include "GfcClasses\x3\Gfc2Polygon.h"

public ref class NGfc2Polygon: public NGfc2Topology
{
public:
    NGfc2Polygon();
    NGfc2Polygon(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
