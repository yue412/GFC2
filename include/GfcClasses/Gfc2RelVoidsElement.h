#ifndef GFC2RELVOIDSELEMENT_H
#define GFC2RELVOIDSELEMENT_H

#include "GfcClasses.h"
#include "Gfc2RelDecomposes.h"
#include "Gfc2Element.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelVoidsElement: public Gfc2RelDecomposes
{
GFCENGINE_DEC_OBJECT(Gfc2RelVoidsElement, gfc::engine::CEntity)
public:
    Gfc2RelVoidsElement();
    Gfc2RelVoidsElement(bool bSetSchema);
    void setRelatedOpeningElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedOpeningElement() const;
    bool hasRelatedOpeningElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatedOpeningElementPtr();
    int getRelatingBuildingElementCount() const;
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatingBuildingElementPtr(int nIndex);

};
#endif
