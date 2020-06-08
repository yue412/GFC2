#ifndef NGFC2STRINGLISTPROPERTY_H
#define NGFC2STRINGLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2StringListProperty.h"
#include "NGfc2String.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2StringListProperty: public NGfc2ListProperty
{
public:
    NGfc2StringListProperty();
    NGfc2StringListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);
    NGfc2String^ getValuesPtr(int nIndex);

};
#endif
