#ifndef NGFC2REFSTRING_H
#define NGFC2REFSTRING_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2RefString.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2RefString: public NGfc2Root
{
public:
    NGfc2RefString();
    NGfc2RefString(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVal(System::String^ sValue);
    System::String^ getVal();
    bool hasVal();

};
#endif
