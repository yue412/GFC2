#ifndef NGFC2SIMPLEVERTEX_H
#define NGFC2SIMPLEVERTEX_H

#include "NGfc2Topology.h"
#include "Gfc2SimpleVertex.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SimpleVertex: public NGfc2Topology
{
public:
    NGfc2SimpleVertex();
    NGfc2SimpleVertex(void* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector2d^ getPointPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setArcType(NGfc2ArcType nValue);
    NGfc2ArcType getArcType();
    bool hasArcType();

};
#endif
