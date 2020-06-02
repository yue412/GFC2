#ifndef NGFC2SIMPLELOOP_H
#define NGFC2SIMPLELOOP_H

#include "NGfc2Topology.h"
#include "Gfc2SimpleLoop.h"
#include "NGfc2SimpleVertex.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SimpleLoop: public NGfc2Topology
{
public:
    NGfc2SimpleLoop();
    NGfc2SimpleLoop(void* pEntity, bool bOwner);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getVertexes(int nIndex);
    NGfc2SimpleVertex^ getVertexesPtr(int nIndex);

};
#endif
