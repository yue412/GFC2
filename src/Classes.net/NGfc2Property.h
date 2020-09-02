#ifndef NGFC2PROPERTY_H
#define NGFC2PROPERTY_H

#include "Gfc2Property.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Property: public glodon::objectbufnet::Entity
{
public:
    NGfc2Property();
    NGfc2Property(void* pEntity, bool bOwner);
    void setName(NGfc2Label sValue);
    NGfc2Label getName();
    bool hasName();
    void setCode(NGfc2String sValue);
    NGfc2String getCode();
    bool hasCode();
    void setExtension(NGfc2String sValue);
    NGfc2String getExtension();
    bool hasExtension();

};
#endif
