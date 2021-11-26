#ifndef NGFC2REPRESENTATION_H
#define NGFC2REPRESENTATION_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2Representation.h"
#include "NGfc2RepresentationItem.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Representation: public NGfc2Root
{
public:
    NGfc2Representation();
    NGfc2Representation(gfc::engine::CEntity* pEntity, bool bOwner);
    void setIdentifier(NGfc2String sValue);
    NGfc2String getIdentifier();
    bool hasIdentifier();
    int getitemsCount();
    void clearitems();
    void additems(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getitems(int nIndex);

};
#endif
