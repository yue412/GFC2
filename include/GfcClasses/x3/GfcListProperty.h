#ifndef GFCLISTPROPERTY_H
#define GFCLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSimpleProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcListProperty: public GfcSimpleProperty
{
GFCENGINE_DEC_OBJECT(GfcListProperty, gfc::engine::CEntity)
public:
    GfcListProperty();
    GfcListProperty(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
