#ifndef NGFC2SINGLEPROPERTY_H
#define NGFC2SINGLEPROPERTY_H

#include "NGfc2SimpleProperty.h"
#include "Gfc2SingleProperty.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SingleProperty: public NGfc2SimpleProperty
{
public:
    NGfc2SingleProperty();
    NGfc2SingleProperty(void* pEntity, bool bOwner);

};
#endif
