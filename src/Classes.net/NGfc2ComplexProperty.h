#ifndef NGFC2COMPLEXPROPERTY_H
#define NGFC2COMPLEXPROPERTY_H

#include "NGfc2Property.h"
#include "GfcClasses\x3\Gfc2ComplexProperty.h"

public ref class NGfc2ComplexProperty: public NGfc2Property
{
public:
    NGfc2ComplexProperty();
    NGfc2ComplexProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex);

};
#endif
