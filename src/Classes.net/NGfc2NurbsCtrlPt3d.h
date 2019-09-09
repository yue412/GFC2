#ifndef NGFC2NURBSCTRLPT3D_H
#define NGFC2NURBSCTRLPT3D_H

#include "Gfc2NurbsCtrlPt3d.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2NurbsCtrlPt3d: public glodon::objectbufnet::Entity
{
public:
    NGfc2NurbsCtrlPt3d();
    NGfc2NurbsCtrlPt3d(void* pEntity, bool bOwner);
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector3d^ getPointPtr();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();

};
#endif
