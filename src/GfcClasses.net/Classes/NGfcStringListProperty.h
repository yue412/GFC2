#ifndef NGFCSTRINGLISTPROPERTY_H
#define NGFCSTRINGLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcStringListProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcStringListProperty: public NGfcListProperty
{
public:
    NGfcStringListProperty();
    NGfcStringListProperty(bool bNoCreate);
    int getValuesCount();
    void clearValues();
    void addValues(NGfcString sValue);
    NGfcString getValues(int nIndex);

};
#endif
