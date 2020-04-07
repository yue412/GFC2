#ifndef NGFC2RELCOVERSBLDGELEMENTS_H
#define NGFC2RELCOVERSBLDGELEMENTS_H

#include "NGfc2RelConnects.h"
#include "Gfc2RelCoversBldgElements.h"
#include "NGfc2Element.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelCoversBldgElements: public NGfc2RelConnects
{
public:
    NGfc2RelCoversBldgElements();
    NGfc2RelCoversBldgElements(void* pEntity, bool bOwner);
    void setRelatingBuildingElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatingBuildingElement();
    bool hasRelatingBuildingElement();
    NGfc2Element^ getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount();
    void clearRelatedCoverings();
    void addRelatedCoverings(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatedCoverings(int nIndex);
    NGfc2Element^ getRelatedCoveringsPtr(int nIndex);

};
#endif
