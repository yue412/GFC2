#ifndef NGFCSIMPLELOOP_H
#define NGFCSIMPLELOOP_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcSimpleLoop.h"
#include "NGfcSimpleVertex.h"

public ref class NGfcSimpleLoop: public NGfcTopology
{
public:
    NGfcSimpleLoop();
    NGfcSimpleLoop(gfc::engine::CEntity* pEntity, bool bOwner);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVertexes(int nIndex);

};
#endif
