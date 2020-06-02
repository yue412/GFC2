#ifndef GFC2POLYHEDRALLOOP_H
#define GFC2POLYHEDRALLOOP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "Gfc2PolyhedralEdge.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PolyhedralLoop: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralLoop,gfc2::engine::EntityFactory)
public:
    Gfc2PolyhedralLoop();
    Gfc2PolyhedralLoop(bool bSetSchema);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getEdges(int nIndex) const;
    std::shared_ptr<Gfc2PolyhedralEdge> getEdgesPtr(int nIndex);

};
#endif
