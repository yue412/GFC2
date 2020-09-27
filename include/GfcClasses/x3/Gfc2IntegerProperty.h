#ifndef GFC2INTEGERPROPERTY_H
#define GFC2INTEGERPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2IntegerProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2IntegerProperty, gfc::engine::CEntity)
public:
    Gfc2IntegerProperty();
    Gfc2IntegerProperty(bool bSetSchema);
    void setVal(const Gfc2Integer& nValue);
    Gfc2Integer getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
