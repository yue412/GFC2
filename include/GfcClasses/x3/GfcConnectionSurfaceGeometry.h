#ifndef GFCCONNECTIONSURFACEGEOMETRY_H
#define GFCCONNECTIONSURFACEGEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcConnectionGeometry.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConnectionSurfaceGeometry: public GfcConnectionGeometry
{
GFCENGINE_DEC_OBJECT(GfcConnectionSurfaceGeometry, gfc::engine::CEntity)
public:
    GfcConnectionSurfaceGeometry();
    GfcConnectionSurfaceGeometry(bool bSetSchema);
    void setSurfaceOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurfaceOnRelatingElement() const;
    bool hasSurfaceOnRelatingElement() const;
    std::shared_ptr<GfcSurface> getSurfaceOnRelatingElementPtr();
    void setSurfaceOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurfaceOnRelatedElement() const;
    bool hasSurfaceOnRelatedElement() const;
    std::shared_ptr<GfcSurface> getSurfaceOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
