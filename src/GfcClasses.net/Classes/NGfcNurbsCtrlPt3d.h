#ifndef NGFCNURBSCTRLPT3D_H
#define NGFCNURBSCTRLPT3D_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcNurbsCtrlPt3d.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsCtrlPt3d: public NGfcRoot
{
public:
    NGfcNurbsCtrlPt3d();
    NGfcNurbsCtrlPt3d(bool bNoCreate);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setWeight(NGfcDouble dValue);
    NGfcDouble getWeight();
    bool hasWeight();

};
#endif
