#ifndef GFCBOOLEANPROPERTY_H
#define GFCBOOLEANPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBooleanProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcBooleanProperty, gfc::engine::CEntity)
public:
    GfcBooleanProperty();
    GfcBooleanProperty(bool bSetSchema);
    void setVal(const GfcBoolean& bValue);
    GfcBoolean getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
