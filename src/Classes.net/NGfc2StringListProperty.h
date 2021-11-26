#ifndef NGFC2STRINGLISTPROPERTY_H
#define NGFC2STRINGLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "GfcClasses\x3\Gfc2StringListProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2StringListProperty: public NGfc2ListProperty
{
public:
    NGfc2StringListProperty();
    NGfc2StringListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfc2String sValue);
    NGfc2String getValues(int nIndex);

};
#endif
