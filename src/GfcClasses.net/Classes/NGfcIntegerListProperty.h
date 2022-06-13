#ifndef NGFCINTEGERLISTPROPERTY_H
#define NGFCINTEGERLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcIntegerListProperty.h"
#include "NTypeDef.h"

public ref class NGfcIntegerListProperty: public NGfcListProperty
{
public:
    NGfcIntegerListProperty();
    NGfcIntegerListProperty(bool bNoCreate);
    int getValuesCount();
    void clearValues();
    void addValues(NGfcInteger nValue);
    NGfcInteger getValues(int nIndex);

};
#endif
