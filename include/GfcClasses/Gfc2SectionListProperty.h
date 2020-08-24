#ifndef GFC2SECTIONLISTPROPERTY_H
#define GFC2SECTIONLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SectionListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2SectionListProperty, gfc::engine::CEntity)
public:
    Gfc2SectionListProperty();
    Gfc2SectionListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Section> getValuesPtr(int nIndex);

};
#endif
