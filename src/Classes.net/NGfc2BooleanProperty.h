#ifndef NGFC2BOOLEANPROPERTY_H
#define NGFC2BOOLEANPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2BooleanProperty.h"
#include "NTypeDef.h"

public ref class NGfc2BooleanProperty: public NGfc2SingleProperty
{
public:
    NGfc2BooleanProperty();
    NGfc2BooleanProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVal(NGfc2Boolean bValue);
    NGfc2Boolean getVal();
    bool hasVal();

};
#endif
