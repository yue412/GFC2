#ifndef NGFC2SWEEP_H
#define NGFC2SWEEP_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Sweep.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"

public ref class NGfc2Sweep: public NGfc2Surface
{
public:
    NGfc2Sweep();
    NGfc2Sweep(gfc::engine::CEntity* pEntity, bool bOwner);
    void setProfile(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getProfile();
    bool hasProfile();
    void setSpine3d(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    void setReferenceVector(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    void setSweepType(NGfc2SweepType nValue);
    NGfc2SweepType getSweepType();
    bool hasSweepType();

};
#endif
