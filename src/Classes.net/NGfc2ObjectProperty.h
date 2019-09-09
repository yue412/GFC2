#ifndef NGFC2OBJECTPROPERTY_H
#define NGFC2OBJECTPROPERTY_H

#include "NGfc2Property.h"
#include "Gfc2ObjectProperty.h"
#include "NGfc2Object.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ObjectProperty: public NGfc2Property
{
public:
    NGfc2ObjectProperty();
    NGfc2ObjectProperty(void* pEntity, bool bOwner);
    void setValue(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getValue();
    bool hasValue();
    NGfc2Object^ getValuePtr();

};
#endif
