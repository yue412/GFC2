#ifndef NGFCPLANECOEF_H
#define NGFCPLANECOEF_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcPlaneCoef.h"
#include "NTypeDef.h"

public ref class NGfcPlaneCoef: public NGfcEntity
{
public:
    NGfcPlaneCoef();
    NGfcPlaneCoef(gfc::engine::CEntity* pEntity, bool bOwner);
    void setA(NGfcDouble dValue);
    NGfcDouble getA();
    bool hasA();
    void setB(NGfcDouble dValue);
    NGfcDouble getB();
    bool hasB();
    void setC(NGfcDouble dValue);
    NGfcDouble getC();
    bool hasC();
    void setD(NGfcDouble dValue);
    NGfcDouble getD();
    bool hasD();

};
#endif
