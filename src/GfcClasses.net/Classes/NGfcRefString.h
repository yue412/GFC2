#ifndef NGFCREFSTRING_H
#define NGFCREFSTRING_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcRefString.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRefString: public NGfcEntity
{
public:
    NGfcRefString();
    NGfcRefString(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVal(System::String^ sValue);
    System::String^ getVal();
    bool hasVal();

};
#endif
