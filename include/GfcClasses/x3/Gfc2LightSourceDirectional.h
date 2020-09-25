#ifndef GFC2LIGHTSOURCEDIRECTIONAL_H
#define GFC2LIGHTSOURCEDIRECTIONAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2LightSource.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2LightSourceDirectional: public Gfc2LightSource
{
GFCENGINE_DEC_OBJECT(Gfc2LightSourceDirectional, gfc::engine::CEntity)
public:
    Gfc2LightSourceDirectional();
    Gfc2LightSourceDirectional(bool bSetSchema);
    void setOrientation(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOrientation() const;
    bool hasOrientation() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getOrientationPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
