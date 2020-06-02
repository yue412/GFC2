#ifndef GFC2POLYHEDRALEDGE_H
#define GFC2POLYHEDRALEDGE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PolyhedralEdge: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralEdge,gfc2::engine::EntityFactory)
public:
    Gfc2PolyhedralEdge();
    Gfc2PolyhedralEdge(bool bSetSchema);
    void setStartVertexIndex(const Gfc2Integer& nValue);
    Gfc2Integer getStartVertexIndex() const;
    bool hasStartVertexIndex() const;
    void setEndVertexIndex(const Gfc2Integer& nValue);
    Gfc2Integer getEndVertexIndex() const;
    bool hasEndVertexIndex() const;

};
#endif
