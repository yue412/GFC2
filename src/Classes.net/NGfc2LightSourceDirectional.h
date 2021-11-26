#ifndef NGFC2LIGHTSOURCEDIRECTIONAL_H
#define NGFC2LIGHTSOURCEDIRECTIONAL_H

#include "NGfc2LightSource.h"
#include "GfcClasses\x3\Gfc2LightSourceDirectional.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2LightSourceDirectional: public NGfc2LightSource
{
public:
    NGfc2LightSourceDirectional();
    NGfc2LightSourceDirectional(gfc::engine::CEntity* pEntity, bool bOwner);
    void setOrientation(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOrientation();
    bool hasOrientation();

};
#endif
