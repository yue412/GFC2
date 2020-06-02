#ifndef NGFC2POLYHEDRONBODY_H
#define NGFC2POLYHEDRONBODY_H

#include "NGfc2Body.h"
#include "Gfc2PolyhedronBody.h"
#include "NGfc2PolyhedralFace.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PolyhedronBody: public NGfc2Body
{
public:
    NGfc2PolyhedronBody();
    NGfc2PolyhedronBody(void* pEntity, bool bOwner);
    int getFacesCount();
    void clearFaces();
    void addFaces(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getFaces(int nIndex);
    NGfc2PolyhedralFace^ getFacesPtr(int nIndex);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getVertexes(int nIndex);
    NGfc2Vector3d^ getVertexesPtr(int nIndex);

};
#endif
