#ifndef NGFC2HERMITECURVE3D_H
#define NGFC2HERMITECURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2HermiteCurve3d.h"
#include "NGfc2HermiteCtrlPt3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2HermiteCurve3d: public NGfc2Curve3d
{
public:
    NGfc2HermiteCurve3d();
    NGfc2HermiteCurve3d(void* pEntity, bool bOwner);
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex);
    NGfc2HermiteCtrlPt3d^ getCtrlPtsPtr(int nIndex);

};
#endif
