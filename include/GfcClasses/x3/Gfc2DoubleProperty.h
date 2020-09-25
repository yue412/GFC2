#ifndef GFC2DOUBLEPROPERTY_H
#define GFC2DOUBLEPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2DoubleProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2DoubleProperty, gfc::engine::CEntity)
public:
    Gfc2DoubleProperty();
    Gfc2DoubleProperty(bool bSetSchema);
    void setVal(const Gfc2Double& dValue);
    Gfc2Double getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
