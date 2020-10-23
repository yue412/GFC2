#ifndef GFC2SECTIONLISTPROPERTY_H
#define GFC2SECTIONLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ListProperty.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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
    std::shared_ptr<Gfc2Section> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
