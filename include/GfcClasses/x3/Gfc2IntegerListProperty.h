#ifndef GFC2INTEGERLISTPROPERTY_H
#define GFC2INTEGERLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2IntegerListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2IntegerListProperty, gfc::engine::CEntity)
public:
    Gfc2IntegerListProperty();
    Gfc2IntegerListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const Gfc2Integer& nValue);
    Gfc2Integer getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
