#ifndef NGFC2NURBSCTRLPT3D_H
#define NGFC2NURBSCTRLPT3D_H

#include "NGfc2Root.h"
#include "Gfc2NurbsCtrlPt3d.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2NurbsCtrlPt3d: public NGfc2Root
{
public:
    NGfc2NurbsCtrlPt3d();
    NGfc2NurbsCtrlPt3d(void* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector3d^ getPointPtr();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();

};
#endif
