#ifndef NGFC2BREPBODY_H
#define NGFC2BREPBODY_H

#include "NGfc2Body.h"
#include "Gfc2BrepBody.h"
#include "NGfc2Face.h"
#include "NGfc2Edge.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2BrepBody: public NGfc2Body
{
public:
    NGfc2BrepBody();
    NGfc2BrepBody(void* pEntity, bool bOwner);
    int getFacesCount();
    void clearFaces();
    void addFaces(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getFaces(int nIndex);
    NGfc2Face^ getFacesPtr(int nIndex);
    int getEdgesCount();
    void clearEdges();
    void addEdges(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEdges(int nIndex);
    NGfc2Edge^ getEdgesPtr(int nIndex);

};
#endif
