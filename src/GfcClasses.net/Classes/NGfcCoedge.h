#ifndef NGFCCOEDGE_H
#define NGFCCOEDGE_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcCoedge.h"
#include "NGfcCurve2d.h"
#include "NTypeDef.h"

public ref class NGfcCoedge: public NGfcTopology
{
public:
    NGfcCoedge();
    NGfcCoedge(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setEdgeIndex(NGfcInteger nValue);
    NGfcInteger getEdgeIndex();
    bool hasEdgeIndex();
    void setEdgeSameDir(NGfcBoolean bValue);
    NGfcBoolean getEdgeSameDir();
    bool hasEdgeSameDir();

};
#endif
