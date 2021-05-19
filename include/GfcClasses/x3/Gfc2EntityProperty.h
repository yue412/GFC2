#ifndef GFC2ENTITYPROPERTY_H
#define GFC2ENTITYPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2EntityProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2EntityProperty, gfc::engine::CEntity)
public:
    Gfc2EntityProperty();
    Gfc2EntityProperty(bool bSetSchema);
    void setVal(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVal() const;
    bool hasVal() const;
    std::shared_ptr<Gfc2Root> getValPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
