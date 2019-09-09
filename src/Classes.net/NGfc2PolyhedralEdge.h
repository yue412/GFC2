#ifndef NGFC2POLYHEDRALEDGE_H
#define NGFC2POLYHEDRALEDGE_H

#include "Gfc2PolyhedralEdge.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PolyhedralEdge: public glodon::objectbufnet::Entity
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
