#ifndef GFC2RELVOIDSELEMENT_H
#define GFC2RELVOIDSELEMENT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelDecomposes.h"
#include "GfcClasses/x3/Gfc2Element.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelVoidsElement: public Gfc2RelDecomposes
{
GFCENGINE_DEC_OBJECT(Gfc2RelVoidsElement, gfc::engine::CEntity)
public:
    Gfc2RelVoidsElement();
    Gfc2RelVoidsElement(bool bSetSchema);
    void setRelatedOpeningElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedOpeningElement() const;
    bool hasRelatedOpeningElement() const;
    std::shared_ptr<Gfc2Element> getRelatedOpeningElementPtr();
    int getRelatingBuildingElementCount() const;
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatingBuildingElementPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
