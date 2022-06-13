#ifndef NGFCNURBSCURVE2D_H
#define NGFCNURBSCURVE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcNurbsCurve2d.h"
#include "NGfcNurbsCtrlPt2d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsCurve2d: public NGfcCurve2d
{
public:
    NGfcNurbsCurve2d();
    NGfcNurbsCurve2d(bool bNoCreate);
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
