#ifndef GFC2POLYHEDRALLOOP_H
#define GFC2POLYHEDRALLOOP_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2PolyhedralEdge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PolyhedralLoop: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralLoop, gfc::engine::CEntity)
public:
    Gfc2PolyhedralLoop();
    Gfc2PolyhedralLoop(bool bSetSchema);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEdges(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2PolyhedralEdge> getEdgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
