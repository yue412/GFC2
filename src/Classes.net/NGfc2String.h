#ifndef NGFC2STRING_H
#define NGFC2STRING_H

#include "Gfc2String.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2String: public glodon::objectbufnet::Entity
{
public:
    NGfc2String();
    NGfc2String(void* pEntity, bool bOwner);
    void setValue(String^ sValue);
    String^ getValue();
    bool hasValue();

};
#endif
