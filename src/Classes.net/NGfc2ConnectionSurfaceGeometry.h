#ifndef NGFC2CONNECTIONSURFACEGEOMETRY_H
#define NGFC2CONNECTIONSURFACEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "Gfc2ConnectionSurfaceGeometry.h"
#include "NGfc2Surface.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConnectionSurfaceGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionSurfaceGeometry();
    NGfc2ConnectionSurfaceGeometry(void* pEntity, bool bOwner);
    void setSurfaceOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurfaceOnRelatingElement();
    bool hasSurfaceOnRelatingElement();
    NGfc2Surface^ getSurfaceOnRelatingElementPtr();
    void setSurfaceOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurfaceOnRelatedElement();
    bool hasSurfaceOnRelatedElement();
    NGfc2Surface^ getSurfaceOnRelatedElementPtr();

};
#endif
