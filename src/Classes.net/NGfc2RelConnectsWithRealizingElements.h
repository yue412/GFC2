#ifndef NGFC2RELCONNECTSWITHREALIZINGELEMENTS_H
#define NGFC2RELCONNECTSWITHREALIZINGELEMENTS_H

#include "NGfc2RelConnectsElements.h"
#include "Gfc2RelConnectsWithRealizingElements.h"
#include "NGfc2Element.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelConnectsWithRealizingElements: public NGfc2RelConnectsElements
{
public:
    NGfc2RelConnectsWithRealizingElements();
    NGfc2RelConnectsWithRealizingElements(void* pEntity, bool bOwner);
    void setRealizingElements(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRealizingElements();
    bool hasRealizingElements();
    NGfc2Element^ getRealizingElementsPtr();

};
#endif
