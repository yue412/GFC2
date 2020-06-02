#ifndef NGFC2CONNECTIONPOINTGEOMETRY_H
#define NGFC2CONNECTIONPOINTGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "Gfc2ConnectionPointGeometry.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConnectionPointGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionPointGeometry();
    NGfc2ConnectionPointGeometry(void* pEntity, bool bOwner);
    void setPointOnRelatingElement(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPointOnRelatingElement();
    bool hasPointOnRelatingElement();
    NGfc2Vector3d^ getPointOnRelatingElementPtr();
    void setPointOnRelatedElement(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPointOnRelatedElement();
    bool hasPointOnRelatedElement();
    NGfc2Vector3d^ getPointOnRelatedElementPtr();

};
#endif
