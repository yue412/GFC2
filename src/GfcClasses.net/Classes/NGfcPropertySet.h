#ifndef NGFCPROPERTYSET_H
#define NGFCPROPERTYSET_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcPropertySet.h"
#include "NGfcProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcPropertySet: public NGfcEntity
{
public:
    NGfcPropertySet();
    NGfcPropertySet(gfc::engine::CEntity* pEntity, bool bOwner);
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex);

};
#endif
