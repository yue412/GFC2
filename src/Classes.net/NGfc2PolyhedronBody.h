#ifndef NGFC2POLYHEDRONBODY_H
#define NGFC2POLYHEDRONBODY_H

#include "NGfc2Body.h"
#include "Gfc2PolyhedronBody.h"
#include "NGfc2PolyhedralFace.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PolyhedronBody: public NGfc2Body
{
public:
    NGfc2PolyhedronBody();
    NGfc2PolyhedronBody(void* pEntity, bool bOwner);
    int getFacesCount();
    void clearFaces();
    void addFaces(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getFaces(int nIndex);
    NGfc2PolyhedralFace^ getFacesPtr(int nIndex);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getVertexes(int nIndex);
    NGfc2Vector3d^ getVertexesPtr(int nIndex);

};
#endif
