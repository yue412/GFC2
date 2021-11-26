#ifndef NGFC2RELVOIDSELEMENT_H
#define NGFC2RELVOIDSELEMENT_H

#include "NGfc2RelDecomposes.h"
#include "GfcClasses\x3\Gfc2RelVoidsElement.h"
#include "NGfc2Element.h"

public ref class NGfc2RelVoidsElement: public NGfc2RelDecomposes
{
public:
    NGfc2RelVoidsElement();
    NGfc2RelVoidsElement(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRelatedOpeningElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedOpeningElement();
    bool hasRelatedOpeningElement();
    int getRelatingBuildingElementCount();
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingBuildingElement(int nIndex);

};
#endif
