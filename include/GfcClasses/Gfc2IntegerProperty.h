#ifndef GFC2INTEGERPROPERTY_H
#define GFC2INTEGERPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

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
#endif
