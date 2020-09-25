#ifndef GFC2RELCONNECTSPATHELEMENTS_H
#define GFC2RELCONNECTSPATHELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelConnectsElements.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelConnectsPathElements: public Gfc2RelConnectsElements
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsPathElements, gfc::engine::CEntity)
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

GFCCLASSES_NAMESPACE_END

#endif
