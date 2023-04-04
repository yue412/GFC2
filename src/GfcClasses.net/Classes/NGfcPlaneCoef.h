#ifndef NGFCPLANECOEF_H
#define NGFCPLANECOEF_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcPlaneCoef.h"
#include "NTypeDef.h"

public ref class NGfcPlaneCoef: public NGfcRoot
{
public:
    NGfcPlaneCoef();
    NGfcPlaneCoef(bool bNoCreate);
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
