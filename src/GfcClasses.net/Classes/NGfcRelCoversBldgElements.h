#ifndef NGFCRELCOVERSBLDGELEMENTS_H
#define NGFCRELCOVERSBLDGELEMENTS_H

#include "NGfcRelConnects.h"
#include "GfcClasses\x3\GfcRelCoversBldgElements.h"
#include "NGfcElement.h"

public ref class NGfcRelCoversBldgElements: public NGfcRelConnects
{
public:
    NGfcRelCoversBldgElements();
    NGfcRelCoversBldgElements(bool bNoCreate);
    void setRelatingBuildingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingBuildingElement();
    bool hasRelatingBuildingElement();
    int getRelatedCoveringsCount();
    void clearRelatedCoverings();
    void addRelatedCoverings(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedCoverings(int nIndex);

};
#endif
