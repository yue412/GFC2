#ifndef GFCSTRINGPROPERTY_H
#define GFCSTRINGPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcStringProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcStringProperty, gfc::engine::CEntity)
public:
    GfcStringProperty();
    GfcStringProperty(bool bSetSchema);
    void setVal(const GfcString& sValue);
    GfcString getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
