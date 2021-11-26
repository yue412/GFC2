#ifndef NGFC2INTEGERLISTPROPERTY_H
#define NGFC2INTEGERLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "GfcClasses\x3\Gfc2IntegerListProperty.h"
#include "NTypeDef.h"

public ref class NGfc2IntegerListProperty: public NGfc2ListProperty
{
public:
    NGfc2IntegerListProperty();
    NGfc2IntegerListProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2Integer nValue);
    NGfc2Integer getValues(int nIndex);

};
#endif
