#ifndef GFC2BOOLEANPROPERTY_H
#define GFC2BOOLEANPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BooleanProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2BooleanProperty, gfc::engine::CEntity)
public:
    Gfc2BooleanProperty();
    Gfc2BooleanProperty(bool bSetSchema);
    void setVal(const Gfc2Boolean& bValue);
    Gfc2Boolean getVal() const;
    bool hasVal() const;

};
#endif
