#ifndef GFCRELCONNECTSWITHREALIZINGELEMENTS_H
#define GFCRELCONNECTSWITHREALIZINGELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRelConnectsElements.h"
#include "GfcClasses/x3/GfcElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelConnectsWithRealizingElements: public GfcRelConnectsElements
{
GFCENGINE_DEC_OBJECT(GfcRelConnectsWithRealizingElements, gfc::engine::CEntity)
public:
    GfcRelConnectsWithRealizingElements();
    GfcRelConnectsWithRealizingElements(bool bSetSchema);
    void setRealizingElements(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRealizingElements() const;
    bool hasRealizingElements() const;
    std::shared_ptr<GfcElement> getRealizingElementsPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
