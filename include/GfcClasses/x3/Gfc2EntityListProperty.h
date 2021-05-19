#ifndef GFC2ENTITYLISTPROPERTY_H
#define GFC2ENTITYLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ListProperty.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2EntityListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2EntityListProperty, gfc::engine::CEntity)
public:
    Gfc2EntityListProperty();
    Gfc2EntityListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    std::shared_ptr<Gfc2Root> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
