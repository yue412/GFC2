#ifndef GFC2CONNECTIONSURFACEGEOMETRY_H
#define GFC2CONNECTIONSURFACEGEOMETRY_H

#include "GfcClasses.h"
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ConnectionSurfaceGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionSurfaceGeometry, gfc::engine::CEntity)
public:
    Gfc2ConnectionSurfaceGeometry();
    Gfc2ConnectionSurfaceGeometry(bool bSetSchema);
    void setSurfaceOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurfaceOnRelatingElement() const;
    bool hasSurfaceOnRelatingElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Surface> getSurfaceOnRelatingElementPtr();
    void setSurfaceOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurfaceOnRelatedElement() const;
    bool hasSurfaceOnRelatedElement() const;
    gfc::engine::CEntityWrapPtr<Gfc2Surface> getSurfaceOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
