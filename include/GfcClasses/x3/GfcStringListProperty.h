#ifndef GFCSTRINGLISTPROPERTY_H
#define GFCSTRINGLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcStringListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcStringListProperty, gfc::engine::CEntity)
public:
    GfcStringListProperty();
    GfcStringListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const GfcString& sValue);
    GfcString getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
