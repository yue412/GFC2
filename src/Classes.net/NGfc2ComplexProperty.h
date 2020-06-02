#ifndef NGFC2COMPLEXPROPERTY_H
#define NGFC2COMPLEXPROPERTY_H

#include "NGfc2Property.h"
#include "Gfc2ComplexProperty.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ComplexProperty: public NGfc2Property
{
public:
    NGfc2ComplexProperty();
    NGfc2ComplexProperty(void* pEntity, bool bOwner);
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getHasProperties(int nIndex);
    NGfc2Property^ getHasPropertiesPtr(int nIndex);

};
#endif
