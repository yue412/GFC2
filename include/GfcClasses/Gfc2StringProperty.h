#ifndef GFC2STRINGPROPERTY_H
#define GFC2STRINGPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "Gfc2String.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2StringProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2StringProperty, gfc::engine::CEntity)
public:
    Gfc2StringProperty();
    Gfc2StringProperty(bool bSetSchema);
    void setValue(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValue() const;
    bool hasValue() const;
    std::shared_ptr<Gfc2String> getValuePtr();

};
#endif