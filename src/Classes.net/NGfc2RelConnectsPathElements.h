#ifndef NGFC2RELCONNECTSPATHELEMENTS_H
#define NGFC2RELCONNECTSPATHELEMENTS_H

#include "NGfc2RelConnectsElements.h"
#include "Gfc2RelConnectsPathElements.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelConnectsPathElements: public NGfc2RelConnectsElements
{
public:
    NGfc2RelConnectsPathElements();
    NGfc2RelConnectsPathElements(void* pEntity, bool bOwner);
    void setRelatedConnectionType(NGfc2ConnectionType nValue);
    NGfc2ConnectionType getRelatedConnectionType();
    bool hasRelatedConnectionType();
    void setRelatingConnectionType(NGfc2ConnectionType nValue);
    NGfc2ConnectionType getRelatingConnectionType();
    bool hasRelatingConnectionType();

};
#endif
