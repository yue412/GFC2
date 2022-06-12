#ifndef NGFCSECTIONPROPERTY_H
#define NGFCSECTIONPROPERTY_H

#include "NGfcSingleProperty.h"
#include "GfcClasses\x3\GfcSectionProperty.h"
#include "NGfcSection.h"

public ref class NGfcSectionProperty: public NGfcSingleProperty
{
public:
    NGfcSectionProperty();
    NGfcSectionProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setSection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSection();
    bool hasSection();

};
#endif
