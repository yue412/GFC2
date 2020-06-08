#ifndef NGFC2RELCONNECTSWITHREALIZINGELEMENTS_H
#define NGFC2RELCONNECTSWITHREALIZINGELEMENTS_H

#include "NGfc2RelConnectsElements.h"
#include "Gfc2RelConnectsWithRealizingElements.h"
#include "NGfc2Element.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelConnectsWithRealizingElements: public NGfc2RelConnectsElements
{
public:
    NGfc2RelConnectsWithRealizingElements();
    NGfc2RelConnectsWithRealizingElements(void* pEntity, bool bOwner);
    void setRealizingElements(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRealizingElements();
    bool hasRealizingElements();
    NGfc2Element^ getRealizingElementsPtr();

};
#endif
