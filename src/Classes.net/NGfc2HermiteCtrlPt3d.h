#ifndef NGFC2HERMITECTRLPT3D_H
#define NGFC2HERMITECTRLPT3D_H

#include "Gfc2HermiteCtrlPt3d.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2HermiteCtrlPt3d: public glodon::objectbufnet::Entity
{
public:
    NGfc2HermiteCtrlPt3d();
    NGfc2HermiteCtrlPt3d(void* pEntity, bool bOwner);
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector3d^ getPointPtr();
    void setTangent(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTangent();
    bool hasTangent();
    NGfc2Vector3d^ getTangentPtr();
    void setParameter(NGfc2Double dValue);
    NGfc2Double getParameter();
    bool hasParameter();

};
#endif
