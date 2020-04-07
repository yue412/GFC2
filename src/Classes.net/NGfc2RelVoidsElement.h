#ifndef NGFC2RELVOIDSELEMENT_H
#define NGFC2RELVOIDSELEMENT_H

#include "NGfc2RelDecomposes.h"
#include "Gfc2RelVoidsElement.h"
#include "NGfc2Element.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelVoidsElement: public NGfc2RelDecomposes
{
public:
    NGfc2RelVoidsElement();
    NGfc2RelVoidsElement(void* pEntity, bool bOwner);
    void setRelatedOpeningElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatedOpeningElement();
    bool hasRelatedOpeningElement();
    NGfc2Element^ getRelatedOpeningElementPtr();
    int getRelatingBuildingElementCount();
    void clearRelatingBuildingElement();
    void addRelatingBuildingElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatingBuildingElement(int nIndex);
    NGfc2Element^ getRelatingBuildingElementPtr(int nIndex);

};
#endif
