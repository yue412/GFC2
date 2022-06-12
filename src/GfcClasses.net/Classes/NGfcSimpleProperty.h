#ifndef NGFCSIMPLEPROPERTY_H
#define NGFCSIMPLEPROPERTY_H

#include "NGfcProperty.h"
#include "GfcClasses\x3\GfcSimpleProperty.h"

public ref class NGfcSimpleProperty: public NGfcProperty
{
public:
    NGfcSimpleProperty();
    NGfcSimpleProperty(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
