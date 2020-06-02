#ifndef NGFC2DOUBLEPROPERTY_H
#define NGFC2DOUBLEPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2DoubleProperty.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2DoubleProperty: public NGfc2SingleProperty
{
public:
    NGfc2DoubleProperty();
    NGfc2DoubleProperty(void* pEntity, bool bOwner);
    void setValue(NGfc2Double dValue);
    NGfc2Double getValue();
    bool hasValue();

};
#endif
