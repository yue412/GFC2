#ifndef NGFC2DOUBLELISTPROPERTY_H
#define NGFC2DOUBLELISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "GfcClasses\x3\Gfc2DoubleListProperty.h"
#include "NTypeDef.h"

public ref class NGfc2DoubleListProperty: public NGfc2ListProperty
{
public:
    NGfc2DoubleListProperty();
    NGfc2DoubleListProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2Double dValue);
    NGfc2Double getValues(int nIndex);

};
#endif
