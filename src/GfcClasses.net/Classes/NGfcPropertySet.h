#ifndef NGFCPROPERTYSET_H
#define NGFCPROPERTYSET_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcPropertySet.h"
#include "NGfcProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcPropertySet: public NGfcRoot
{
public:
    NGfcPropertySet();
    NGfcPropertySet(bool bNoCreate);
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex);

};
#endif
