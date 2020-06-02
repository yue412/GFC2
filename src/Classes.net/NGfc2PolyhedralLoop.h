#ifndef NGFC2POLYHEDRALLOOP_H
#define NGFC2POLYHEDRALLOOP_H

#include "NGfc2Topology.h"
#include "Gfc2PolyhedralLoop.h"
#include "NGfc2PolyhedralEdge.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PolyhedralLoop: public NGfc2Topology
{
public:
    NGfc2PolyhedralLoop();
    NGfc2PolyhedralLoop(void* pEntity, bool bOwner);
    int getEdgesCount();
    void clearEdges();
    void addEdges(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getEdges(int nIndex);
    NGfc2PolyhedralEdge^ getEdgesPtr(int nIndex);

};
#endif
