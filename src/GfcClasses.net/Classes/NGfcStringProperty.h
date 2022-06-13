#ifndef NGFCSTRINGPROPERTY_H
#define NGFCSTRINGPROPERTY_H

#include "NGfcSingleProperty.h"
#include "GfcClasses\x3\GfcStringProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcStringProperty: public NGfcSingleProperty
{
public:
    NGfcStringProperty();
    NGfcStringProperty(bool bNoCreate);
    void setVal(NGfcString sValue);
    NGfcString getVal();
    bool hasVal();

};
#endif
