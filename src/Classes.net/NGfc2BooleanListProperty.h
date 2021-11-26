#ifndef NGFC2BOOLEANLISTPROPERTY_H
#define NGFC2BOOLEANLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "GfcClasses\x3\Gfc2BooleanListProperty.h"
#include "NTypeDef.h"

public ref class NGfc2BooleanListProperty: public NGfc2ListProperty
{
public:
    NGfc2BooleanListProperty();
    NGfc2BooleanListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2Boolean bValue);
    NGfc2Boolean getValues(int nIndex);

};
#endif
