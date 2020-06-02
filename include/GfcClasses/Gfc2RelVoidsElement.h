#ifndef GFC2RELVOIDSELEMENT_H
#define GFC2RELVOIDSELEMENT_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelDecomposes.h"
#include "Gfc2Element.h"
#include "Gfc2Element.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelVoidsElement: public Gfc2RelDecomposes
{
GFCENGINE_DEC_OBJECT(Gfc2RelVoidsElement,gfc2::engine::EntityFactory)
public:
    Gfc2RelVoidsElement();
    Gfc2RelVoidsElement(bool bSetSchema);
    void setRelatedOpeningElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatedOpeningElement() const;
    bool hasRelatedOpeningElement() const;
    std::shared_ptr<Gfc2Element> getRelatedOpeningElementPtr();
    int getRelatingBuildingElementCount() const;
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingBuildingElement(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatingBuildingElementPtr(int nIndex);

};
#endif
