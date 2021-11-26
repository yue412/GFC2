#ifndef NGFC2RELCOVERSBLDGELEMENTS_H
#define NGFC2RELCOVERSBLDGELEMENTS_H

#include "NGfc2RelConnects.h"
#include "GfcClasses\x3\Gfc2RelCoversBldgElements.h"
#include "NGfc2Element.h"

public ref class NGfc2RelCoversBldgElements: public NGfc2RelConnects
{
public:
    NGfc2RelCoversBldgElements();
    NGfc2RelCoversBldgElements(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRelatingBuildingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingBuildingElement();
    bool hasRelatingBuildingElement();
    int getRelatedCoveringsCount();
    void clearRelatedCoverings();
    void addRelatedCoverings(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex);

};
#endif
