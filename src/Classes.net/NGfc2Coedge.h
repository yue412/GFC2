#ifndef NGFC2COEDGE_H
#define NGFC2COEDGE_H

#include "NGfc2Topology.h"
#include "Gfc2Coedge.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Coedge: public NGfc2Topology
{
public:
    NGfc2Coedge();
    NGfc2Coedge(void* pEntity, bool bOwner);
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();
    void setEdgeIndex(NGfc2Integer nValue);
    NGfc2Integer getEdgeIndex();
    bool hasEdgeIndex();
    void setEdgeSameDir(NGfc2Boolean bValue);
    NGfc2Boolean getEdgeSameDir();
    bool hasEdgeSameDir();

};
#endif
