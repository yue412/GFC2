#ifndef NGFC2HERMITECURVE2D_H
#define NGFC2HERMITECURVE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2HermiteCurve2d.h"
#include "NGfc2HermiteCtrlPt2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2HermiteCurve2d: public NGfc2Curve2d
{
public:
    NGfc2HermiteCurve2d();
    NGfc2HermiteCurve2d(void* pEntity, bool bOwner);
    int getCtrlPtsCount();
    void clearCtrlPts();
    void addCtrlPts(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex);
    NGfc2HermiteCtrlPt2d^ getCtrlPtsPtr(int nIndex);

};
#endif
