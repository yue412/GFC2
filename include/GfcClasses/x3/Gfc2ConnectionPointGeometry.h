#ifndef GFC2CONNECTIONPOINTGEOMETRY_H
#define GFC2CONNECTIONPOINTGEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ConnectionGeometry.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ConnectionPointGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionPointGeometry, gfc::engine::CEntity)
public:
    Gfc2ConnectionPointGeometry();
    Gfc2ConnectionPointGeometry(bool bSetSchema);
    void setPointOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPointOnRelatingElement() const;
    bool hasPointOnRelatingElement() const;
    std::shared_ptr<Gfc2Vector3d> getPointOnRelatingElementPtr();
    void setPointOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPointOnRelatedElement() const;
    bool hasPointOnRelatedElement() const;
    std::shared_ptr<Gfc2Vector3d> getPointOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
