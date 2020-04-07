#ifndef NGFC2LIGHTSOURCEDIRECTIONAL_H
#define NGFC2LIGHTSOURCEDIRECTIONAL_H

#include "NGfc2LightSource.h"
#include "Gfc2LightSourceDirectional.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LightSourceDirectional: public NGfc2LightSource
{
public:
    NGfc2LightSourceDirectional();
    NGfc2LightSourceDirectional(void* pEntity, bool bOwner);
    void setOrientation(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getOrientation();
    bool hasOrientation();
    NGfc2Vector3d^ getOrientationPtr();

};
#endif
