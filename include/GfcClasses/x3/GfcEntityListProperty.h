#ifndef GFCENTITYLISTPROPERTY_H
#define GFCENTITYLISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEntityListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcEntityListProperty, gfc::engine::CEntity)
public:
    GfcEntityListProperty();
    GfcEntityListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    std::shared_ptr<GfcRoot> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
