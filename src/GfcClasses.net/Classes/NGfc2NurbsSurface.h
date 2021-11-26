#ifndef NGFC2NURBSSURFACE_H
#define NGFC2NURBSSURFACE_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2NurbsSurface.h"
#include "NGfc2NurbsCtrlPt3d.h"
#include "NTypeDef.h"

public ref class NGfc2NurbsSurface: public NGfc2Surface
{
public:
    NGfc2NurbsSurface();
    NGfc2NurbsSurface(gfc::engine::CEntity* pEntity, bool bOwner);
    void setDegreeU(NGfc2Integer nValue);
    NGfc2Integer getDegreeU();
    bool hasDegreeU();
    void setDegreeV(NGfc2Integer nValue);
    NGfc2Integer getDegreeV();
    bool hasDegreeV();
    void setCtrlPtCountU(NGfc2Integer nValue);
    NGfc2Integer getCtrlPtCountU();
    bool hasCtrlPtCountU();
    void setCtrlPtCountV(NGfc2Integer nValue);
    NGfc2Integer getCtrlPtCountV();
    bool hasCtrlPtCountV();
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex);
    int getKnotsUCount();
    void clearKnotsU();
    void addKnotsU(NGfc2Double dValue);
    NGfc2Double getKnotsU(int nIndex);
    int getKnotsVCount();
    void clearKnotsV();
    void addKnotsV(NGfc2Double dValue);
    NGfc2Double getKnotsV(int nIndex);

};
#endif
