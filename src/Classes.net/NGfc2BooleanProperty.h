#ifndef NGFC2BOOLEANPROPERTY_H
#define NGFC2BOOLEANPROPERTY_H

#include "NGfc2Property.h"
#include "Gfc2BooleanProperty.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2BooleanProperty: public NGfc2Property
{
public:
    NGfc2BooleanProperty();
    NGfc2BooleanProperty(void* pEntity, bool bOwner);
    void setValue(NGfc2Boolean bValue);
    NGfc2Boolean getValue();
    bool hasValue();

};
#endif
