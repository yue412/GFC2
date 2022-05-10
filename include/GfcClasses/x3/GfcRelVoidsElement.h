#ifndef GFCRELVOIDSELEMENT_H
#define GFCRELVOIDSELEMENT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRelDecomposes.h"
#include "GfcClasses/x3/GfcElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelVoidsElement: public GfcRelDecomposes
{
GFCENGINE_DEC_OBJECT(GfcRelVoidsElement, gfc::engine::CEntity)
public:
    GfcRelVoidsElement();
    GfcRelVoidsElement(bool bSetSchema);
    void setRelatedOpeningElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedOpeningElement() const;
    bool hasRelatedOpeningElement() const;
    std::shared_ptr<GfcElement> getRelatedOpeningElementPtr();
    int getRelatingBuildingElementCount() const;
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement(int nIndex) const;
    std::shared_ptr<GfcElement> getRelatingBuildingElementPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
