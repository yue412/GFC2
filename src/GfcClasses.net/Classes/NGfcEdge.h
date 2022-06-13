#ifndef NGFCEDGE_H
#define NGFCEDGE_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcEdge.h"
#include "NGfcCurve3d.h"
#include "NTypeDef.h"

public ref class NGfcEdge: public NGfcTopology
{
public:
    NGfcEdge();
    NGfcEdge(bool bNoCreate);
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setFaceIndex1(NGfcInteger nValue);
    NGfcInteger getFaceIndex1();
    bool hasFaceIndex1();
    void setFaceIndex2(NGfcInteger nValue);
    NGfcInteger getFaceIndex2();
    bool hasFaceIndex2();
    void setLoopIndex1(NGfcInteger nValue);
    NGfcInteger getLoopIndex1();
    bool hasLoopIndex1();
    void setLoopIndex2(NGfcInteger nValue);
    NGfcInteger getLoopIndex2();
    bool hasLoopIndex2();
    void setCoedgeIndex1(NGfcInteger nValue);
    NGfcInteger getCoedgeIndex1();
    bool hasCoedgeIndex1();
    void setCoedgeIndex2(NGfcInteger nValue);
    NGfcInteger getCoedgeIndex2();
    bool hasCoedgeIndex2();

};
#endif
