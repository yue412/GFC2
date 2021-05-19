#ifndef NGFC2ENTITYPROPERTY_H
#define NGFC2ENTITYPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2EntityProperty.h"
#include "NGfc2Root.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2EntityProperty: public NGfc2SingleProperty
{
public:
    NGfc2EntityProperty();
    NGfc2EntityProperty(void* pEntity, bool bOwner);
    void setVal(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVal();
    bool hasVal();
    NGfc2Root^ getValPtr();

};
#endif
