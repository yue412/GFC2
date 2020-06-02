#ifndef NGFC2NURBSCURVE3D_H
#define NGFC2NURBSCURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2NurbsCurve3d.h"
#include "NGfc2NurbsCtrlPt3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2NurbsCurve3d: public NGfc2Curve3d
{
public:
    NGfc2NurbsCurve3d();
    NGfc2NurbsCurve3d(void* pEntity, bool bOwner);
    void setDegree(NGfc2Integer nValue);
    NGfc2Integer getDegree();
    bool hasDegree();
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCtrlPts(int nIndex);
    NGfc2NurbsCtrlPt3d^ getCtrlPtsPtr(int nIndex);
    int getKnotsCount();
    void clearKnots();
    void addKnots(NGfc2Double dValue);
    NGfc2Double getKnots(int nIndex);

};
#endif
