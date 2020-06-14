#ifndef GFC2RELCONNECTSELEMENTS_H
#define GFC2RELCONNECTSELEMENTS_H

#include "GfcClasses.h"
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "Gfc2ConnectionGeometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsElements, gfc::engine::CEntity)
public:
    Gfc2RelConnectsElements();
    Gfc2RelConnectsElements(bool bSetSchema);
    void setRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingElement() const;
    bool hasRelatingElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatingElementPtr();
    void setRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedElement() const;
    bool hasRelatedElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Element> getRelatedElementPtr();
    void setConnectionGeometry(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getConnectionGeometry() const;
    bool hasConnectionGeometry() const;
    gfc::engine::CEntityWrapPtr<Gfc2ConnectionGeometry> getConnectionGeometryPtr();

};
#endif
