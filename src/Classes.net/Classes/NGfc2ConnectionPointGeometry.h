#ifndef NGFC2CONNECTIONPOINTGEOMETRY_H
#define NGFC2CONNECTIONPOINTGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "GfcClasses\x3\Gfc2ConnectionPointGeometry.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2ConnectionPointGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionPointGeometry();
    NGfc2ConnectionPointGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPointOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPointOnRelatingElement();
    bool hasPointOnRelatingElement();
    void setPointOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPointOnRelatedElement();
    bool hasPointOnRelatedElement();

};
#endif
