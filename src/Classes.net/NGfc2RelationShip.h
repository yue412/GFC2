#ifndef NGFC2RELATIONSHIP_H
#define NGFC2RELATIONSHIP_H

#include "NGfc2Root.h"
#include "Gfc2RelationShip.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2RelationShip: public NGfc2Root
{
public:
    NGfc2RelationShip();
    NGfc2RelationShip(void* pEntity, bool bOwner);
    void setName(NGfc2Label sValue);
    NGfc2Label getName();
    bool hasName();

};
#endif
