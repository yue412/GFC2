#ifndef NGFC2PLANECOEF_H
#define NGFC2PLANECOEF_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2PlaneCoef.h"
#include "NTypeDef.h"

public ref class NGfc2PlaneCoef: public NGfc2Root
{
public:
    NGfc2PlaneCoef();
    NGfc2PlaneCoef(gfc::engine::CEntity* pEntity, bool bOwner);
    void setA(NGfc2Double dValue);
    NGfc2Double getA();
    bool hasA();
    void setB(NGfc2Double dValue);
    NGfc2Double getB();
    bool hasB();
    void setC(NGfc2Double dValue);
    NGfc2Double getC();
    bool hasC();
    void setD(NGfc2Double dValue);
    NGfc2Double getD();
    bool hasD();

};
#endif
