#ifndef GFC2RELCONNECTSWITHREALIZINGELEMENTS_H
#define GFC2RELCONNECTSWITHREALIZINGELEMENTS_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelConnectsElements.h"
#include "Gfc2Element.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsWithRealizingElements: public Gfc2RelConnectsElements
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsWithRealizingElements,gfc2::engine::EntityFactory)
public:
    Gfc2RelConnectsWithRealizingElements();
    Gfc2RelConnectsWithRealizingElements(bool bSetSchema);
    void setRealizingElements(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRealizingElements() const;
    bool hasRealizingElements() const;
    std::shared_ptr<Gfc2Element> getRealizingElementsPtr();

};
#endif
