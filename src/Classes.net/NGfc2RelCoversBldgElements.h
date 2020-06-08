#ifndef NGFC2RELCOVERSBLDGELEMENTS_H
#define NGFC2RELCOVERSBLDGELEMENTS_H

#include "NGfc2RelConnects.h"
#include "Gfc2RelCoversBldgElements.h"
#include "NGfc2Element.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelCoversBldgElements: public NGfc2RelConnects
{
public:
    NGfc2RelCoversBldgElements();
    NGfc2RelCoversBldgElements(void* pEntity, bool bOwner);
    void setRelatingBuildingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingBuildingElement();
    bool hasRelatingBuildingElement();
    NGfc2Element^ getRelatingBuildingElementPtr();
    int getRelatedCoveringsCount();
    void clearRelatedCoverings();
    void addRelatedCoverings(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex);
    NGfc2Element^ getRelatedCoveringsPtr(int nIndex);

};
#endif
