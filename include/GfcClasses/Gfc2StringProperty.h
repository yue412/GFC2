#ifndef GFC2STRINGPROPERTY_H
#define GFC2STRINGPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

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
#endif
