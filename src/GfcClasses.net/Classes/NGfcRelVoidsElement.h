#ifndef NGFCRELVOIDSELEMENT_H
#define NGFCRELVOIDSELEMENT_H

#include "NGfcRelDecomposes.h"
#include "GfcClasses\x3\GfcRelVoidsElement.h"
#include "NGfcElement.h"

public ref class NGfcRelVoidsElement: public NGfcRelDecomposes
{
public:
    NGfcRelVoidsElement();
    NGfcRelVoidsElement(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRelatedOpeningElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedOpeningElement();
    bool hasRelatedOpeningElement();
    int getRelatingBuildingElementCount();
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingBuildingElement(int nIndex);

};
#endif
