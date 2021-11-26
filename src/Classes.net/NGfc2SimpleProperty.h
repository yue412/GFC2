#ifndef NGFC2SIMPLEPROPERTY_H
#define NGFC2SIMPLEPROPERTY_H

#include "NGfc2Property.h"
#include "GfcClasses\x3\Gfc2SimpleProperty.h"

public ref class NGfc2SimpleProperty: public NGfc2Property
{
public:
    NGfc2SimpleProperty();
    NGfc2SimpleProperty(void* pEntity, bool bOwner);

};
#endif
