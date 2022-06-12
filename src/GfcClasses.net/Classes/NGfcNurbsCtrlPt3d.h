#ifndef NGFCNURBSCTRLPT3D_H
#define NGFCNURBSCTRLPT3D_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcNurbsCtrlPt3d.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsCtrlPt3d: public NGfcEntity
{
public:
    NGfcNurbsCtrlPt3d();
    NGfcNurbsCtrlPt3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setWeight(NGfcDouble dValue);
    NGfcDouble getWeight();
    bool hasWeight();

};
#endif
