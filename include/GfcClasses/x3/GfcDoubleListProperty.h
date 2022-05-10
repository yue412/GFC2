#ifndef GFCDOUBLELISTPROPERTY_H
#define GFCDOUBLELISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcDoubleListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcDoubleListProperty, gfc::engine::CEntity)
public:
    GfcDoubleListProperty();
    GfcDoubleListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const GfcDouble& dValue);
    GfcDouble getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
