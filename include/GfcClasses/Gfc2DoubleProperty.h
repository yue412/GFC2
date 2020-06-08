#ifndef GFC2DOUBLEPROPERTY_H
#define GFC2DOUBLEPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2DoubleProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2DoubleProperty, gfc::engine::CEntity)
public:
    Gfc2DoubleProperty();
    Gfc2DoubleProperty(bool bSetSchema);
    void setValue(const Gfc2Double& dValue);
    Gfc2Double getValue() const;
    bool hasValue() const;

};
#endif
