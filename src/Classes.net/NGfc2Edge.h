#ifndef NGFC2EDGE_H
#define NGFC2EDGE_H

#include "Gfc2Edge.h"
#include "NGfc2Curve3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Edge: public glodon::objectbufnet::Entity
{
public:
    NGfc2Edge();
    NGfc2Edge(void* pEntity, bool bOwner);
    void setCurve(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve3d^ getCurvePtr();
    void setFaceIndex1(NGfc2Integer nValue);
    NGfc2Integer getFaceIndex1();
    bool hasFaceIndex1();
    void setFaceIndex2(NGfc2Integer nValue);
    NGfc2Integer getFaceIndex2();
    bool hasFaceIndex2();
    void setLoopIndex1(NGfc2Integer nValue);
    NGfc2Integer getLoopIndex1();
    bool hasLoopIndex1();
    void setLoopIndex2(NGfc2Integer nValue);
    NGfc2Integer getLoopIndex2();
    bool hasLoopIndex2();
    void setCoedgeIndex1(NGfc2Integer nValue);
    NGfc2Integer getCoedgeIndex1();
    bool hasCoedgeIndex1();
    void setCoedgeIndex2(NGfc2Integer nValue);
    NGfc2Integer getCoedgeIndex2();
    bool hasCoedgeIndex2();

};
#endif
