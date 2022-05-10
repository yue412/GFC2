#ifndef GFCSIMPLEPROPERTY_H
#define GFCSIMPLEPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSimpleProperty: public GfcProperty
{
GFCENGINE_DEC_OBJECT(GfcSimpleProperty, gfc::engine::CEntity)
public:
    GfcSimpleProperty();
    GfcSimpleProperty(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
