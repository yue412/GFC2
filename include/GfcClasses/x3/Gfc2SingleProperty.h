#ifndef GFC2SINGLEPROPERTY_H
#define GFC2SINGLEPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SimpleProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SingleProperty: public Gfc2SimpleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2SingleProperty, gfc::engine::CEntity)
public:
    Gfc2SingleProperty();
    Gfc2SingleProperty(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
