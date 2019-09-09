#ifndef NGFC2STRINGPROPERTY_H
#define NGFC2STRINGPROPERTY_H

#include "NGfc2Property.h"
#include "Gfc2StringProperty.h"
#include "NGfc2String.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2StringProperty: public NGfc2Property
{
public:
    NGfc2StringProperty();
    NGfc2StringProperty(void* pEntity, bool bOwner);
    void setValue(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getValue();
    bool hasValue();
    NGfc2String^ getValuePtr();

};
#endif
