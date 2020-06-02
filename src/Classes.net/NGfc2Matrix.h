#ifndef NGFC2MATRIX_H
#define NGFC2MATRIX_H

#include "NGfc2Geometry.h"
#include "Gfc2Matrix.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Matrix: public NGfc2Geometry
{
public:
    NGfc2Matrix();
    NGfc2Matrix(void* pEntity, bool bOwner);
    void setDim(NGfc2Integer nValue);
    NGfc2Integer getDim();
    bool hasDim();
    int getDataCount();
    void clearData();
    void addData(NGfc2Double dValue);
    NGfc2Double getData(int nIndex);

};
#endif
