#ifndef NGFC2SIMPLELOOP_H
#define NGFC2SIMPLELOOP_H

#include "NGfc2Topology.h"
#include "GfcClasses\x3\Gfc2SimpleLoop.h"
#include "NGfc2SimpleVertex.h"

public ref class NGfc2SimpleLoop: public NGfc2Topology
{
public:
    NGfc2SimpleLoop();
    NGfc2SimpleLoop(gfc::engine::CEntity* pEntity, bool bOwner);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVertexes(int nIndex);

};
#endif
