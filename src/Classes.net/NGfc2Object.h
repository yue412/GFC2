#ifndef NGFC2OBJECT_H
#define NGFC2OBJECT_H

#include "Gfc2Object.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Object: public glodon::objectbufnet::Entity
{
public:
    NGfc2Object();
    NGfc2Object(void* pEntity, bool bOwner);
    void setID(NGfc2Identity sValue);
    NGfc2Identity getID();
    bool hasID();
    void setName(NGfc2Label sValue);
    NGfc2Label getName();
    bool hasName();

};
#endif
