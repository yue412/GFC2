#ifndef NGFCNURBSCTRLPT2D_H
#define NGFCNURBSCTRLPT2D_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcNurbsCtrlPt2d.h"
#include "NGfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsCtrlPt2d: public NGfcEntity
{
public:
    NGfcNurbsCtrlPt2d();
    NGfcNurbsCtrlPt2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setWeight(NGfcDouble dValue);
    NGfcDouble getWeight();
    bool hasWeight();

};
#endif
