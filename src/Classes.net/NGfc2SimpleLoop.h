#ifndef NGFC2SIMPLELOOP_H
#define NGFC2SIMPLELOOP_H

#include "NGfc2Topology.h"
#include "Gfc2SimpleLoop.h"
#include "NGfc2SimpleVertex.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SimpleLoop: public NGfc2Topology
{
public:
    NGfc2SimpleLoop();
    NGfc2SimpleLoop(void* pEntity, bool bOwner);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getVertexes(int nIndex);
    NGfc2SimpleVertex^ getVertexesPtr(int nIndex);

};
#endif
