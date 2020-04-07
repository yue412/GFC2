#ifndef NGFC2LISTPROPERTY_H
#define NGFC2LISTPROPERTY_H

#include "NGfc2SimpleProperty.h"
#include "Gfc2ListProperty.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ListProperty: public NGfc2SimpleProperty
{
public:
    NGfc2ListProperty();
    NGfc2ListProperty(void* pEntity, bool bOwner);

};
#endif
