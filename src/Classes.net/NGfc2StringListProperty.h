#ifndef NGFC2STRINGLISTPROPERTY_H
#define NGFC2STRINGLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2StringListProperty.h"
#include "NGfc2String.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2StringListProperty: public NGfc2ListProperty
{
public:
    NGfc2StringListProperty();
    NGfc2StringListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getValues(int nIndex);
    NGfc2String^ getValuesPtr(int nIndex);

};
#endif
