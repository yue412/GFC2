#ifndef NGFC2POLYHEDRALLOOP_H
#define NGFC2POLYHEDRALLOOP_H

#include "Gfc2PolyhedralLoop.h"
#include "NGfc2PolyhedralEdge.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PolyhedralLoop: public glodon::objectbufnet::Entity
{
public:
    NGfc2PolyhedralLoop();
    NGfc2PolyhedralLoop(void* pEntity, bool bOwner);
    int getEdgesCount();
    void clearEdges();
    void addEdges(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEdges(int nIndex);
    NGfc2PolyhedralEdge^ getEdgesPtr(int nIndex);

};
#endif
