#ifndef GFC2SIMPLEPROPERTY_H
#define GFC2SIMPLEPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2Property.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SimpleProperty: public Gfc2Property
{
GFCENGINE_DEC_OBJECT(Gfc2SimpleProperty, gfc::engine::Entity)
public:
    Gfc2SimpleProperty();
    Gfc2SimpleProperty(bool bSetSchema);

};
#endif
