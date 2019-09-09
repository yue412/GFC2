#ifndef NGFC2EDGEDATA_H
#define NGFC2EDGEDATA_H

#include "Gfc2EdgeData.h"
#include "NGfc2String.h"
#include "NGfc2Polygon.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2EdgeData: public glodon::objectbufnet::Entity
{
public:
    NGfc2EdgeData();
    NGfc2EdgeData(void* pEntity, bool bOwner);
    void setEdgeIndex(NGfc2Integer nValue);
    NGfc2Integer getEdgeIndex();
    bool hasEdgeIndex();
    void setLoopIndex(NGfc2Integer nValue);
    NGfc2Integer getLoopIndex();
    bool hasLoopIndex();
    void setType(NGfc2Integer nValue);
    NGfc2Integer getType();
    bool hasType();
    void setEdgeInfo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEdgeInfo();
    bool hasEdgeInfo();
    NGfc2String^ getEdgeInfoPtr();
    void setParam(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getParam();
    bool hasParam();
    NGfc2String^ getParamPtr();
    void setBaseType(NGfc2Integer nValue);
    NGfc2Integer getBaseType();
    bool hasBaseType();
    void setSlopePoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSlopePoly();
    bool hasSlopePoly();
    NGfc2Polygon^ getSlopePolyPtr();

};
#endif
