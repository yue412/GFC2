#ifndef NGFC2INTEGERPROPERTY_H
#define NGFC2INTEGERPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2IntegerProperty.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2IntegerProperty: public NGfc2SingleProperty
{
public:
    NGfc2IntegerProperty();
    NGfc2IntegerProperty(void* pEntity, bool bOwner);
    void setValue(NGfc2Integer nValue);
    NGfc2Integer getValue();
    bool hasValue();

};
#endif
