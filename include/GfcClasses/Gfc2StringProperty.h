#ifndef GFC2STRINGPROPERTY_H
#define GFC2STRINGPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "Gfc2String.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2StringProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2StringProperty, gfc2::engine::Entity)
public:
    Gfc2StringProperty();
    Gfc2StringProperty(bool bSetSchema);
    void setValue(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getValue() const;
    bool hasValue() const;
    std::shared_ptr<Gfc2String> getValuePtr();

};
#endif
