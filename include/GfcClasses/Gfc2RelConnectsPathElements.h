#ifndef GFC2RELCONNECTSPATHELEMENTS_H
#define GFC2RELCONNECTSPATHELEMENTS_H

#include "GfcClasses.h"
#include "Gfc2RelConnectsElements.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsPathElements: public Gfc2RelConnectsElements
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsPathElements, gfc2::engine::Entity)
public:
    Gfc2RelConnectsPathElements();
    Gfc2RelConnectsPathElements(bool bSetSchema);
    void setRelatedConnectionType(const Gfc2ConnectionType& nValue);
    Gfc2ConnectionType getRelatedConnectionType() const;
    bool hasRelatedConnectionType() const;
    void setRelatingConnectionType(const Gfc2ConnectionType& nValue);
    Gfc2ConnectionType getRelatingConnectionType() const;
    bool hasRelatingConnectionType() const;

};
#endif
