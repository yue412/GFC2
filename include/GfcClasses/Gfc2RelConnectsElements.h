#ifndef GFC2RELCONNECTSELEMENTS_H
#define GFC2RELCONNECTSELEMENTS_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "Gfc2Element.h"
#include "Gfc2ConnectionGeometry.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsElements: public Gfc2RelConnects
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnectsElements,gfc2::engine::EntityFactory)
public:
    Gfc2RelConnectsElements();
    Gfc2RelConnectsElements(bool bSetSchema);
    void setRelatingElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingElement() const;
    bool hasRelatingElement() const;
    std::shared_ptr<Gfc2Element> getRelatingElementPtr();
    void setRelatedElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatedElement() const;
    bool hasRelatedElement() const;
    std::shared_ptr<Gfc2Element> getRelatedElementPtr();
    void setConnectionGeometry(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getConnectionGeometry() const;
    bool hasConnectionGeometry() const;
    std::shared_ptr<Gfc2ConnectionGeometry> getConnectionGeometryPtr();

};
#endif
