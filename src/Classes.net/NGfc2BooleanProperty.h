#ifndef NGFC2BOOLEANPROPERTY_H
#define NGFC2BOOLEANPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2BooleanProperty.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BooleanProperty: public NGfc2SingleProperty
{
public:
    NGfc2BooleanProperty();
    NGfc2BooleanProperty(void* pEntity, bool bOwner);
    void setVal(NGfc2Boolean bValue);
    NGfc2Boolean getVal();
    bool hasVal();

};
#endif
