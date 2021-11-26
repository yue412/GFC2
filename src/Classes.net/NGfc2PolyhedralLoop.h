#ifndef NGFC2POLYHEDRALLOOP_H
#define NGFC2POLYHEDRALLOOP_H

#include "NGfc2Topology.h"
#include "GfcClasses\x3\Gfc2PolyhedralLoop.h"
#include "NGfc2PolyhedralEdge.h"

public ref class NGfc2PolyhedralLoop: public NGfc2Topology
{
public:
    NGfc2PolyhedralLoop();
    NGfc2PolyhedralLoop(void* pEntity, bool bOwner);
    int getEdgesCount();
    void clearEdges();
    void addEdges(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEdges(int nIndex);

};
#endif
