#ifndef GFC2POLYHEDRALEDGE_H
#define GFC2POLYHEDRALEDGE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Topology.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PolyhedralEdge: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralEdge, gfc::engine::CEntity)
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

GFCCLASSES_NAMESPACE_END

#endif
