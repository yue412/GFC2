#ifndef NGFC2DOUBLEPROPERTY_H
#define NGFC2DOUBLEPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2DoubleProperty.h"
#include "NTypeDef.h"

public ref class NGfc2DoubleProperty: public NGfc2SingleProperty
{
public:
    NGfc2DoubleProperty();
    NGfc2DoubleProperty(void* pEntity, bool bOwner);
    void setVal(NGfc2Double dValue);
    NGfc2Double getVal();
    bool hasVal();

};
#endif
