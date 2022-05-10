#ifndef GFCBOOLEANLISTPROPERTY_H
#define GFCBOOLEANLISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBooleanListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcBooleanListProperty, gfc::engine::CEntity)
public:
    GfcBooleanListProperty();
    GfcBooleanListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const GfcBoolean& bValue);
    GfcBoolean getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
