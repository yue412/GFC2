#ifndef GFC2RELCOVERSBLDGELEMENTS_H
#define GFC2RELCOVERSBLDGELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelConnects.h"
#include "GfcClasses/x3/Gfc2Element.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelCoversBldgElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelCoversBldgElements, gfc::engine::CEntity)
public:
    Gfc2RelCoversBldgElements();
    Gfc2RelCoversBldgElements(bool bSetSchema);
    void setRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement() const;
    bool hasRelatingBuildingElement() const;
    std::shared_ptr<Gfc2Element> getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount() const;
    void clearRelatedCoverings();
    void addRelatedCoverings(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatedCoveringsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
