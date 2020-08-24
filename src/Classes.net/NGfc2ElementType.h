#ifndef NGFC2ELEMENTTYPE_H
#define NGFC2ELEMENTTYPE_H

#include "NGfc2Object.h"
#include "Gfc2ElementType.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2ElementType: public NGfc2Object
{
public:
    NGfc2ElementType();
    NGfc2ElementType(void* pEntity, bool bOwner);
    void setEType(NGfc2Label sValue);
    NGfc2Label getEType();
    bool hasEType();

};
#endif
