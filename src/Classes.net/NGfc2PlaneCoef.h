#ifndef NGFC2PLANECOEF_H
#define NGFC2PLANECOEF_H

#include "Gfc2PlaneCoef.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PlaneCoef: public glodon::objectbufnet::Entity
{
public:
    NGfc2PlaneCoef();
    NGfc2PlaneCoef(void* pEntity, bool bOwner);
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
