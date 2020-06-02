#ifndef GFC2CONNECTIONPOINTGEOMETRY_H
#define GFC2CONNECTIONPOINTGEOMETRY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ConnectionPointGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionPointGeometry,gfc2::engine::EntityFactory)
public:
    Gfc2ConnectionPointGeometry();
    Gfc2ConnectionPointGeometry(bool bSetSchema);
    void setPointOnRelatingElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPointOnRelatingElement() const;
    bool hasPointOnRelatingElement() const;
    std::shared_ptr<Gfc2Vector3d> getPointOnRelatingElementPtr();
    void setPointOnRelatedElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPointOnRelatedElement() const;
    bool hasPointOnRelatedElement() const;
    std::shared_ptr<Gfc2Vector3d> getPointOnRelatedElementPtr();

};
#endif
