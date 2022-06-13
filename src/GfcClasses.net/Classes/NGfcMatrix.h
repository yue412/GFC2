#ifndef NGFCMATRIX_H
#define NGFCMATRIX_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcMatrix.h"
#include "NTypeDef.h"

public ref class NGfcMatrix: public NGfcGeometry
{
public:
    NGfcMatrix();
    NGfcMatrix(bool bNoCreate);
    void setDim(NGfcInteger nValue);
    NGfcInteger getDim();
    bool hasDim();
    int getDataCount();
    void clearData();
    void addData(NGfcDouble dValue);
    NGfcDouble getData(int nIndex);

};
#endif
