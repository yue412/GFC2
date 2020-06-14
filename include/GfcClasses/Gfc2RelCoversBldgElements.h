#ifndef GFC2RELCOVERSBLDGELEMENTS_H
#define GFC2RELCOVERSBLDGELEMENTS_H

#include "GfcClasses.h"
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelCoversBldgElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelCoversBldgElements, gfc::engine::CEntity)
public:
    Gfc2RelCoversBldgElements();
    Gfc2RelCoversBldgElements(bool bSetSchema);
    void setRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement() const;
    bool hasRelatingBuildingElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount() const;
    void clearRelatedCoverings();
    void addRelatedCoverings(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatedCoveringsPtr(int nIndex);

};
#endif
