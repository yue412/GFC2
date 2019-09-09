#ifndef NGFC2NURBSSURFACE_H
#define NGFC2NURBSSURFACE_H

#include "NGfc2Surface.h"
#include "Gfc2NurbsSurface.h"
#include "NGfc2NurbsCtrlPt3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2NurbsSurface: public NGfc2Surface
{
public:
    NGfc2NurbsSurface();
    NGfc2NurbsSurface(void* pEntity, bool bOwner);
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
    void addCtrlPts(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex);
    NGfc2NurbsCtrlPt3d^ getCtrlPtsPtr(int nIndex);
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
