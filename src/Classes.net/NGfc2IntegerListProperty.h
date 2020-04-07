#ifndef NGFC2INTEGERLISTPROPERTY_H
#define NGFC2INTEGERLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2IntegerListProperty.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2IntegerListProperty: public NGfc2ListProperty
{
public:
    NGfc2IntegerListProperty();
    NGfc2IntegerListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2Integer nValue);
    NGfc2Integer getValues(int nIndex);

};
#endif
