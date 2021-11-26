#ifndef NGFC2RELCONNECTSPATHELEMENTS_H
#define NGFC2RELCONNECTSPATHELEMENTS_H

#include "NGfc2RelConnectsElements.h"
#include "GfcClasses\x3\Gfc2RelConnectsPathElements.h"
#include "NTypeDef.h"

public ref class NGfc2RelConnectsPathElements: public NGfc2RelConnectsElements
{
public:
    NGfc2RelConnectsPathElements();
    NGfc2RelConnectsPathElements(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRelatedConnectionType(NGfc2ConnectionType nValue);
    NGfc2ConnectionType getRelatedConnectionType();
    bool hasRelatedConnectionType();
    void setRelatingConnectionType(NGfc2ConnectionType nValue);
    NGfc2ConnectionType getRelatingConnectionType();
    bool hasRelatingConnectionType();

};
#endif
