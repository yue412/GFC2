#ifndef GFC2SECTIONLISTPROPERTY_H
#define GFC2SECTIONLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SectionListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2SectionListProperty, gfc::engine::Entity)
public:
    Gfc2SectionListProperty();
    Gfc2SectionListProperty(bool bSetSchema);
    int getValueCount() const;
    void clearValue();
    void addValue(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValue(int nIndex) const;
    std::shared_ptr<Gfc2Section> getValuePtr(int nIndex);

};
#endif
