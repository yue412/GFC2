#ifndef NGFCBREPBODY_H
#define NGFCBREPBODY_H

#include "NGfcBody.h"
#include "GfcClasses\x3\GfcBrepBody.h"
#include "NGfcFace.h"
#include "NGfcEdge.h"

public ref class NGfcBrepBody: public NGfcBody
{
public:
    NGfcBrepBody();
    NGfcBrepBody(gfc::engine::CEntity* pEntity, bool bOwner);
    int getFacesCount();
    void clearFaces();
    void addFaces(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getFaces(int nIndex);
    int getEdgesCount();
    void clearEdges();
    void addEdges(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEdges(int nIndex);

};
#endif
