#ifndef GFC2RELCONNECTSELEMENTS_H
#define GFC2RELCONNECTSELEMENTS_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelConnects.h"
#include "GfcClasses/x3/Gfc2Element.h"
#include "GfcClasses/x3/Gfc2ConnectionGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelConnectsElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsElements, gfc::engine::CEntity)
public:
    Gfc2RelConnectsElements();
    Gfc2RelConnectsElements(bool bSetSchema);
    void setRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingElement() const;
    bool hasRelatingElement() const;
    std::shared_ptr<Gfc2Element> getRelatingElementPtr();
    void setRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedElement() const;
    bool hasRelatedElement() const;
    std::shared_ptr<Gfc2Element> getRelatedElementPtr();
    void setConnectionGeometry(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getConnectionGeometry() const;
    bool hasConnectionGeometry() const;
    std::shared_ptr<Gfc2ConnectionGeometry> getConnectionGeometryPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
