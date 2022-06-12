#ifndef NGFCRELCONNECTSELEMENTS_H
#define NGFCRELCONNECTSELEMENTS_H

#include "NGfcRelConnects.h"
#include "GfcClasses\x3\GfcRelConnectsElements.h"
#include "NGfcElement.h"
#include "NGfcConnectionGeometry.h"

public ref class NGfcRelConnectsElements: public NGfcRelConnects
{
public:
    NGfcRelConnectsElements();
    NGfcRelConnectsElements(gfc::engine::CEntity* pEntity, bool bOwner);
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
