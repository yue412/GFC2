#ifndef GFCRELCOVERSBLDGELEMENTS_H
#define GFCRELCOVERSBLDGELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRelConnects.h"
#include "GfcClasses/x3/GfcElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelCoversBldgElements: public GfcRelConnects
{
GFCENGINE_DEC_OBJECT(GfcRelCoversBldgElements, gfc::engine::CEntity)
public:
    GfcRelCoversBldgElements();
    GfcRelCoversBldgElements(bool bSetSchema);
    void setRelatingBuildingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingBuildingElement() const;
    bool hasRelatingBuildingElement() const;
    std::shared_ptr<GfcElement> getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount() const;
    void clearRelatedCoverings();
    void addRelatedCoverings(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex) const;
    std::shared_ptr<GfcElement> getRelatedCoveringsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
