#ifndef GFC2BOOLEANPROPERTY_H
#define GFC2BOOLEANPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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

GFCCLASSES_NAMESPACE_END

#endif
