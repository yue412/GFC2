#ifndef NGFC2SIMPLEVERTEX_H
#define NGFC2SIMPLEVERTEX_H

#include "Gfc2SimpleVertex.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SimpleVertex: public glodon::objectbufnet::Entity
{
public:
    NGfc2SimpleVertex();
    NGfc2SimpleVertex(void* pEntity, bool bOwner);
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
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
