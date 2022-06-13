#ifndef NGFCBOOLEANLISTPROPERTY_H
#define NGFCBOOLEANLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcBooleanListProperty.h"
#include "NTypeDef.h"

public ref class NGfcBooleanListProperty: public NGfcListProperty
{
public:
    NGfcBooleanListProperty();
    NGfcBooleanListProperty(bool bNoCreate);
    int getValuesCount();
    void clearValues();
    void addValues(NGfcBoolean bValue);
    NGfcBoolean getValues(int nIndex);

};
#endif
