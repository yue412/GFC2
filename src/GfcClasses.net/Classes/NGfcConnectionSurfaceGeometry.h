#ifndef NGFCCONNECTIONSURFACEGEOMETRY_H
#define NGFCCONNECTIONSURFACEGEOMETRY_H

#include "NGfcConnectionGeometry.h"
#include "GfcClasses\x3\GfcConnectionSurfaceGeometry.h"
#include "NGfcSurface.h"

public ref class NGfcConnectionSurfaceGeometry: public NGfcConnectionGeometry
{
public:
    NGfcConnectionSurfaceGeometry();
    NGfcConnectionSurfaceGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setSurfaceOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurfaceOnRelatingElement();
    bool hasSurfaceOnRelatingElement();
    void setSurfaceOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurfaceOnRelatedElement();
    bool hasSurfaceOnRelatedElement();

};
#endif
