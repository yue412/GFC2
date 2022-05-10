#ifndef GFCCOMPLEXPROPERTY_H
#define GFCCOMPLEXPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcComplexProperty: public GfcProperty
{
GFCENGINE_DEC_OBJECT(GfcComplexProperty, gfc::engine::CEntity)
public:
    GfcComplexProperty();
    GfcComplexProperty(bool bSetSchema);
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex) const;
    std::shared_ptr<GfcProperty> getHasPropertiesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
