#ifndef GFCRELCONNECTSPATHELEMENTS_H
#define GFCRELCONNECTSPATHELEMENTS_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelConnectsElements.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelConnectsPathElements: public GfcRelConnectsElements
{
GFCENGINE_DEC_OBJECT(GfcRelConnectsPathElements, gfc::engine::CEntity)
public:
    GfcRelConnectsPathElements();
    GfcRelConnectsPathElements(bool bSetSchema);
    void setRelatedConnectionType(const GfcConnectionType& nValue);
    GfcConnectionType getRelatedConnectionType() const;
    bool hasRelatedConnectionType() const;
    void setRelatingConnectionType(const GfcConnectionType& nValue);
    GfcConnectionType getRelatingConnectionType() const;
    bool hasRelatingConnectionType() const;

};

GFCCLASSES_NAMESPACE_END

#endif
