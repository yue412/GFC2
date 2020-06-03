#ifndef GFC2BOOLEANPROPERTY_H
#define GFC2BOOLEANPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BooleanProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2BooleanProperty, gfc::engine::Entity)
public:
    Gfc2BooleanProperty();
    Gfc2BooleanProperty(bool bSetSchema);
    void setValue(const Gfc2Boolean& bValue);
    Gfc2Boolean getValue() const;
    bool hasValue() const;

};
#endif
