#ifndef NGFC2HERMITECTRLPT2D_H
#define NGFC2HERMITECTRLPT2D_H

#include "Gfc2HermiteCtrlPt2d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2HermiteCtrlPt2d: public glodon::objectbufnet::Entity
{
public:
    NGfc2HermiteCtrlPt2d();
    NGfc2HermiteCtrlPt2d(void* pEntity, bool bOwner);
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector2d^ getPointPtr();
    void setTangent(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTangent();
    bool hasTangent();
    NGfc2Vector2d^ getTangentPtr();
    void setParameter(NGfc2Double dValue);
    NGfc2Double getParameter();
    bool hasParameter();

};
#endif
