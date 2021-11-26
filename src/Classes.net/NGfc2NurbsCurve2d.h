#ifndef NGFC2NURBSCURVE2D_H
#define NGFC2NURBSCURVE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2NurbsCurve2d.h"
#include "NGfc2NurbsCtrlPt2d.h"
#include "NTypeDef.h"

public ref class NGfc2NurbsCurve2d: public NGfc2Curve2d
{
public:
    NGfc2NurbsCurve2d();
    NGfc2NurbsCurve2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setDegree(NGfc2Integer nValue);
    NGfc2Integer getDegree();
    bool hasDegree();
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex);
    int getKnotsCount();
    void clearKnots();
    void addKnots(NGfc2Double dValue);
    NGfc2Double getKnots(int nIndex);

};
#endif
