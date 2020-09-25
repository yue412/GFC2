#ifndef GFC2DOUBLELISTPROPERTY_H
#define GFC2DOUBLELISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2DoubleListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2DoubleListProperty, gfc::engine::CEntity)
public:
    Gfc2DoubleListProperty();
    Gfc2DoubleListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const Gfc2Double& dValue);
    Gfc2Double getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
