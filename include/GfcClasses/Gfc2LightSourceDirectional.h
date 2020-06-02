#ifndef GFC2LIGHTSOURCEDIRECTIONAL_H
#define GFC2LIGHTSOURCEDIRECTIONAL_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2LightSource.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2LightSourceDirectional: public Gfc2LightSource
{
GFCENGINE_DEC_OBJECT(Gfc2LightSourceDirectional,gfc2::engine::EntityFactory)
public:
    Gfc2LightSourceDirectional();
    Gfc2LightSourceDirectional(bool bSetSchema);
    void setOrientation(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getOrientation() const;
    bool hasOrientation() const;
    std::shared_ptr<Gfc2Vector3d> getOrientationPtr();

};
#endif
