#ifndef GFC2STRINGPROPERTY_H
#define GFC2STRINGPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2StringProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2StringProperty, gfc::engine::CEntity)
public:
    Gfc2StringProperty();
    Gfc2StringProperty(bool bSetSchema);
    void setVal(const Gfc2String& sValue);
    Gfc2String getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
