#ifndef NGFC2ENTITYPROPERTY_H
#define NGFC2ENTITYPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2EntityProperty.h"
#include "NGfc2Root.h"

public ref class NGfc2EntityProperty: public NGfc2SingleProperty
{
public:
    NGfc2EntityProperty();
    NGfc2EntityProperty(void* pEntity, bool bOwner);
    void setVal(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVal();
    bool hasVal();

};
#endif
