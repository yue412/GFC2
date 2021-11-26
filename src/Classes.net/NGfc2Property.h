#ifndef NGFC2PROPERTY_H
#define NGFC2PROPERTY_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2Property.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Property: public NGfc2Root
{
public:
    NGfc2Property();
    NGfc2Property(gfc::engine::CEntity* pEntity, bool bOwner);
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
