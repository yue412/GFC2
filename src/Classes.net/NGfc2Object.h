#ifndef NGFC2OBJECT_H
#define NGFC2OBJECT_H

#include "NGfc2Root.h"
#include "Gfc2Object.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Object: public NGfc2Root
{
public:
    NGfc2Object();
    NGfc2Object(void* pEntity, bool bOwner);
    void setID(NGfc2Identity sValue);
    NGfc2Identity getID();
    bool hasID();
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();

};
#endif
