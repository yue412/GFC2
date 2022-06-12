#ifndef NGFCCONNECTIONPOINTGEOMETRY_H
#define NGFCCONNECTIONPOINTGEOMETRY_H

#include "NGfcConnectionGeometry.h"
#include "GfcClasses\x3\GfcConnectionPointGeometry.h"
#include "NGfcVector3d.h"

public ref class NGfcConnectionPointGeometry: public NGfcConnectionGeometry
{
public:
    NGfcConnectionPointGeometry();
    NGfcConnectionPointGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPointOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPointOnRelatingElement();
    bool hasPointOnRelatingElement();
    void setPointOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPointOnRelatedElement();
    bool hasPointOnRelatedElement();

};
#endif
