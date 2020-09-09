#ifndef GFC2LISTPROPERTY_H
#define GFC2LISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SimpleProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ListProperty: public Gfc2SimpleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2ListProperty, gfc::engine::CEntity)
public:
    Gfc2ListProperty();
    Gfc2ListProperty(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
