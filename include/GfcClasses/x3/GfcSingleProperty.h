#ifndef GFCSINGLEPROPERTY_H
#define GFCSINGLEPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSimpleProperty.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSingleProperty: public GfcSimpleProperty
{
GFCENGINE_DEC_OBJECT(GfcSingleProperty, gfc::engine::CEntity)
public:
    GfcSingleProperty();
    GfcSingleProperty(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
