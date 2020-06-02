#ifndef NGFC2SWEEP_H
#define NGFC2SWEEP_H

#include "NGfc2Surface.h"
#include "Gfc2Sweep.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Sweep: public NGfc2Surface
{
public:
    NGfc2Sweep();
    NGfc2Sweep(void* pEntity, bool bOwner);
    void setProfile(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getProfile();
    bool hasProfile();
    NGfc2Curve2d^ getProfilePtr();
    void setSpine3d(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    NGfc2Curve3d^ getSpine3dPtr();
    void setReferenceVector(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    NGfc2Vector3d^ getReferenceVectorPtr();
    void setSweepType(NGfc2SweepType nValue);
    NGfc2SweepType getSweepType();
    bool hasSweepType();

};
#endif
