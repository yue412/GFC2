#ifndef GFCRELCONNECTSELEMENTS_H
#define GFCRELCONNECTSELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRelConnects.h"
#include "GfcClasses/x3/GfcElement.h"
#include "GfcClasses/x3/GfcConnectionGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelConnectsElements: public GfcRelConnects
{
GFCENGINE_DEC_OBJECT(GfcRelConnectsElements, gfc::engine::CEntity)
public:
    GfcRelConnectsElements();
    GfcRelConnectsElements(bool bSetSchema);
    void setRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingElement() const;
    bool hasRelatingElement() const;
    std::shared_ptr<GfcElement> getRelatingElementPtr();
    void setRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedElement() const;
    bool hasRelatedElement() const;
    std::shared_ptr<GfcElement> getRelatedElementPtr();
    void setConnectionGeometry(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getConnectionGeometry() const;
    bool hasConnectionGeometry() const;
    std::shared_ptr<GfcConnectionGeometry> getConnectionGeometryPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
