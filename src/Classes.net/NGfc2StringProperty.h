#ifndef NGFC2STRINGPROPERTY_H
#define NGFC2STRINGPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2StringProperty.h"
#include "NGfc2String.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2StringProperty: public NGfc2SingleProperty
{
public:
    NGfc2StringProperty();
    NGfc2StringProperty(void* pEntity, bool bOwner);
    void setValue(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValue();
    bool hasValue();
    NGfc2String^ getValuePtr();

};
#endif
