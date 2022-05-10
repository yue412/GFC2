#ifndef GFCCONNECTIONPOINTGEOMETRY_H
#define GFCCONNECTIONPOINTGEOMETRY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcConnectionGeometry.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConnectionPointGeometry: public GfcConnectionGeometry
{
GFCENGINE_DEC_OBJECT(GfcConnectionPointGeometry, gfc::engine::CEntity)
public:
    GfcConnectionPointGeometry();
    GfcConnectionPointGeometry(bool bSetSchema);
    void setPointOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPointOnRelatingElement() const;
    bool hasPointOnRelatingElement() const;
    std::shared_ptr<GfcVector3d> getPointOnRelatingElementPtr();
    void setPointOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPointOnRelatedElement() const;
    bool hasPointOnRelatedElement() const;
    std::shared_ptr<GfcVector3d> getPointOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
