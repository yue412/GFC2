#ifndef NGFCLISTPROPERTY_H
#define NGFCLISTPROPERTY_H

#include "NGfcSimpleProperty.h"
#include "GfcClasses\x3\GfcListProperty.h"

public ref class NGfcListProperty: public NGfcSimpleProperty
{
public:
    NGfcListProperty();
    NGfcListProperty(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
