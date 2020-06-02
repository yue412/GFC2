#ifndef GFC2RELCOVERSBLDGELEMENTS_H
#define GFC2RELCOVERSBLDGELEMENTS_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelCoversBldgElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelCoversBldgElements,gfc2::engine::EntityFactory)
public:
    Gfc2RelCoversBldgElements();
    Gfc2RelCoversBldgElements(bool bSetSchema);
    void setRelatingBuildingElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingBuildingElement() const;
    bool hasRelatingBuildingElement() const;
    std::shared_ptr<Gfc2Element> getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount() const;
    void clearRelatedCoverings();
    void addRelatedCoverings(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatedCoverings(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatedCoveringsPtr(int nIndex);

};
#endif
