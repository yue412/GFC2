#ifndef NGFC2SIMPLELOOP_H
#define NGFC2SIMPLELOOP_H

#include "Gfc2SimpleLoop.h"
#include "NGfc2SimpleVertex.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SimpleLoop: public glodon::objectbufnet::Entity
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
