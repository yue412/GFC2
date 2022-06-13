#ifndef NGFCNURBSSURFACE_H
#define NGFCNURBSSURFACE_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcNurbsSurface.h"
#include "NGfcNurbsCtrlPt3d.h"
#include "NTypeDef.h"

public ref class NGfcNurbsSurface: public NGfcSurface
{
public:
    NGfcNurbsSurface();
    NGfcNurbsSurface(bool bNoCreate);
    void setDegreeU(NGfcInteger nValue);
    NGfcInteger getDegreeU();
    bool hasDegreeU();
    void setDegreeV(NGfcInteger nValue);
    NGfcInteger getDegreeV();
    bool hasDegreeV();
    void setCtrlPtCountU(NGfcInteger nValue);
    NGfcInteger getCtrlPtCountU();
    bool hasCtrlPtCountU();
    void setCtrlPtCountV(NGfcInteger nValue);
    NGfcInteger getCtrlPtCountV();
    bool hasCtrlPtCountV();
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex);
    int getKnotsUCount();
    void clearKnotsU();
    void addKnotsU(NGfcDouble dValue);
    NGfcDouble getKnotsU(int nIndex);
    int getKnotsVCount();
    void clearKnotsV();
    void addKnotsV(NGfcDouble dValue);
    NGfcDouble getKnotsV(int nIndex);

};
#endif
