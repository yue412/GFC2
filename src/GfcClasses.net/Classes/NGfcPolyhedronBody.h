#ifndef NGFCPOLYHEDRONBODY_H
#define NGFCPOLYHEDRONBODY_H

#include "NGfcBody.h"
#include "GfcClasses\x3\GfcPolyhedronBody.h"
#include "NGfcPolyhedralFace.h"
#include "NGfcVector3d.h"

public ref class NGfcPolyhedronBody: public NGfcBody
{
public:
    NGfcPolyhedronBody();
    NGfcPolyhedronBody(bool bNoCreate);
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
