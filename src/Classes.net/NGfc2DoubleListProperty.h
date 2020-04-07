#ifndef NGFC2DOUBLELISTPROPERTY_H
#define NGFC2DOUBLELISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2DoubleListProperty.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2DoubleListProperty: public NGfc2ListProperty
{
public:
    NGfc2DoubleListProperty();
    NGfc2DoubleListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2Double dValue);
    NGfc2Double getValues(int nIndex);

};
#endif
