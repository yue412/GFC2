#ifndef NGFC2POLYHEDRALEDGE_H
#define NGFC2POLYHEDRALEDGE_H

#include "NGfc2Topology.h"
#include "Gfc2PolyhedralEdge.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PolyhedralEdge: public NGfc2Topology
{
public:
    NGfc2PolyhedralEdge();
    NGfc2PolyhedralEdge(void* pEntity, bool bOwner);
    void setStartVertexIndex(NGfc2Integer nValue);
    NGfc2Integer getStartVertexIndex();
    bool hasStartVertexIndex();
    void setEndVertexIndex(NGfc2Integer nValue);
    NGfc2Integer getEndVertexIndex();
    bool hasEndVertexIndex();

};
#endif
