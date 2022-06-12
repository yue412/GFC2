#ifndef NGFCNURBSCURVE3D_H
#define NGFCNURBSCURVE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcNurbsCurve3d.h"
#include "NGfcNurbsCtrlPt3d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsCurve3d: public NGfcCurve3d
{
public:
    NGfcNurbsCurve3d();
    NGfcNurbsCurve3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setDegree(NGfcInteger nValue);
    NGfcInteger getDegree();
    bool hasDegree();
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex);
    int getKnotsCount();
    void clearKnots();
    void addKnots(NGfcDouble dValue);
    NGfcDouble getKnots(int nIndex);

};
#endif
