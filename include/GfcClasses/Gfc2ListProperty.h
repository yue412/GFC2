#ifndef GFC2LISTPROPERTY_H
#define GFC2LISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SimpleProperty.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ListProperty: public Gfc2SimpleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2ListProperty, gfc::engine::Entity)
public:
    Gfc2ListProperty();
    Gfc2ListProperty(bool bSetSchema);

};
#endif
