#ifndef NGFC2PROPERTYSET_H
#define NGFC2PROPERTYSET_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2PropertySet.h"
#include "NGfc2Property.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2PropertySet: public NGfc2Root
{
public:
    NGfc2PropertySet();
    NGfc2PropertySet(gfc::engine::CEntity* pEntity, bool bOwner);
    void setName(NGfc2Label sValue);
    NGfc2Label getName();
    bool hasName();
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex);

};
#endif
