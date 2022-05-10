#ifndef GFCSECTIONLISTPROPERTY_H
#define GFCSECTIONLISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSectionListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcSectionListProperty, gfc::engine::CEntity)
public:
    GfcSectionListProperty();
    GfcSectionListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    std::shared_ptr<GfcSection> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
