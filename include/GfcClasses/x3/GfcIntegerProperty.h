#ifndef GFCINTEGERPROPERTY_H
#define GFCINTEGERPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIntegerProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcIntegerProperty, gfc::engine::CEntity)
public:
    GfcIntegerProperty();
    GfcIntegerProperty(bool bSetSchema);
    void setVal(const GfcInteger& nValue);
    GfcInteger getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
