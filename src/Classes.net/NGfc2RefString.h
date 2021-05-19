#ifndef NGFC2REFSTRING_H
#define NGFC2REFSTRING_H

#include "NGfc2Root.h"
#include "Gfc2RefString.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2RefString: public NGfc2Root
{
public:
    NGfc2RefString();
    NGfc2RefString(void* pEntity, bool bOwner);
    void setVal(String^ sValue);
    String^ getVal();
    bool hasVal();

};
#endif
