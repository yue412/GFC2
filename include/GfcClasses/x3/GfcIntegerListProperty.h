#ifndef GFCINTEGERLISTPROPERTY_H
#define GFCINTEGERLISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIntegerListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcIntegerListProperty, gfc::engine::CEntity)
public:
    GfcIntegerListProperty();
    GfcIntegerListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const GfcInteger& nValue);
    GfcInteger getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
