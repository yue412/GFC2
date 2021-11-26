#ifndef NGFC2LISTPROPERTY_H
#define NGFC2LISTPROPERTY_H

#include "NGfc2SimpleProperty.h"
#include "GfcClasses\x3\Gfc2ListProperty.h"

public ref class NGfc2ListProperty: public NGfc2SimpleProperty
{
public:
    NGfc2ListProperty();
    NGfc2ListProperty(void* pEntity, bool bOwner);

};
#endif
