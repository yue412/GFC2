#ifndef NGFC2POLYHEDRONBODY_H
#define NGFC2POLYHEDRONBODY_H

#include "NGfc2Body.h"
#include "GfcClasses\x3\Gfc2PolyhedronBody.h"
#include "NGfc2PolyhedralFace.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2PolyhedronBody: public NGfc2Body
{
public:
    NGfc2PolyhedronBody();
    NGfc2PolyhedronBody(void* pEntity, bool bOwner);
    int getFacesCount();
    void clearFaces();
    void addFaces(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getFaces(int nIndex);
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVertexes(int nIndex);

};
#endif
