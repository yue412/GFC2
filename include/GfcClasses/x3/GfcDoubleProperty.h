#ifndef GFCDOUBLEPROPERTY_H
#define GFCDOUBLEPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcDoubleProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcDoubleProperty, gfc::engine::CEntity)
public:
    GfcDoubleProperty();
    GfcDoubleProperty(bool bSetSchema);
    void setVal(const GfcDouble& dValue);
    GfcDouble getVal() const;
    bool hasVal() const;

};

GFCCLASSES_NAMESPACE_END

#endif
