#ifndef NGFCREFSTRING_H
#define NGFCREFSTRING_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcRefString.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRefString: public NGfcRoot
{
public:
    NGfcRefString();
    NGfcRefString(bool bNoCreate);
    void setVal(System::String^ sValue);
    System::String^ getVal();
    bool hasVal();

};
#endif
