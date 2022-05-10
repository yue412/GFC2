#ifndef GFCLIGHTSOURCEDIRECTIONAL_H
#define GFCLIGHTSOURCEDIRECTIONAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcLightSource.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLightSourceDirectional: public GfcLightSource
{
GFCENGINE_DEC_OBJECT(GfcLightSourceDirectional, gfc::engine::CEntity)
public:
    GfcLightSourceDirectional();
    GfcLightSourceDirectional(bool bSetSchema);
    void setOrientation(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOrientation() const;
    bool hasOrientation() const;
    std::shared_ptr<GfcVector3d> getOrientationPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
