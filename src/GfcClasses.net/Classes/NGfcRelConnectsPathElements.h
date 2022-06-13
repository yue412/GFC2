#ifndef NGFCRELCONNECTSPATHELEMENTS_H
#define NGFCRELCONNECTSPATHELEMENTS_H

#include "NGfcRelConnectsElements.h"
#include "GfcClasses\x3\GfcRelConnectsPathElements.h"
#include "NTypeDef.h"

public ref class NGfcRelConnectsPathElements: public NGfcRelConnectsElements
{
public:
    NGfcRelConnectsPathElements();
    NGfcRelConnectsPathElements(bool bNoCreate);
    void setRelatedConnectionType(NGfcConnectionType nValue);
    NGfcConnectionType getRelatedConnectionType();
    bool hasRelatedConnectionType();
    void setRelatingConnectionType(NGfcConnectionType nValue);
    NGfcConnectionType getRelatingConnectionType();
    bool hasRelatingConnectionType();

};
#endif
