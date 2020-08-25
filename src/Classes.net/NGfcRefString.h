#ifndef NGFCREFSTRING_H
#define NGFCREFSTRING_H

#include "GfcRefString.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRefString: public glodon::objectbufnet::Entity
{
public:
    NGfcRefString();
    NGfcRefString(void* pEntity, bool bOwner);
    void setVal(String^ sValue);
    String^ getVal();
    bool hasVal();

};
#endif
