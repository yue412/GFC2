#ifndef NGFCRELCONNECTSWITHREALIZINGELEMENTS_H
#define NGFCRELCONNECTSWITHREALIZINGELEMENTS_H

#include "NGfcRelConnectsElements.h"
#include "GfcClasses\x3\GfcRelConnectsWithRealizingElements.h"
#include "NGfcElement.h"

public ref class NGfcRelConnectsWithRealizingElements: public NGfcRelConnectsElements
{
public:
    NGfcRelConnectsWithRealizingElements();
    NGfcRelConnectsWithRealizingElements(bool bNoCreate);
    void setRealizingElements(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRealizingElements();
    bool hasRealizingElements();

};
#endif
