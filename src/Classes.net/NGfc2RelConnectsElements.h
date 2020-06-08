#ifndef NGFC2RELCONNECTSELEMENTS_H
#define NGFC2RELCONNECTSELEMENTS_H

#include "NGfc2RelConnects.h"
#include "Gfc2RelConnectsElements.h"
#include "NGfc2Element.h"
#include "NGfc2ConnectionGeometry.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelConnectsElements: public NGfc2RelConnects
{
public:
    NGfc2RelConnectsElements();
    NGfc2RelConnectsElements(void* pEntity, bool bOwner);
    void setRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingElement();
    bool hasRelatingElement();
    NGfc2Element^ getRelatingElementPtr();
    void setRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedElement();
    bool hasRelatedElement();
    NGfc2Element^ getRelatedElementPtr();
    void setConnectionGeometry(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getConnectionGeometry();
    bool hasConnectionGeometry();
    NGfc2ConnectionGeometry^ getConnectionGeometryPtr();

};
#endif