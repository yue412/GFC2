#ifndef NGFC2RELCONNECTSELEMENTS_H
#define NGFC2RELCONNECTSELEMENTS_H

#include "NGfc2RelConnects.h"
#include "GfcClasses\x3\Gfc2RelConnectsElements.h"
#include "NGfc2Element.h"
#include "NGfc2ConnectionGeometry.h"

public ref class NGfc2RelConnectsElements: public NGfc2RelConnects
{
public:
    NGfc2RelConnectsElements();
    NGfc2RelConnectsElements(void* pEntity, bool bOwner);
    void setRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingElement();
    bool hasRelatingElement();
    void setRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedElement();
    bool hasRelatedElement();
    void setConnectionGeometry(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getConnectionGeometry();
    bool hasConnectionGeometry();

};
#endif
