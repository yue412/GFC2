#ifndef NGFC2SWEEPCURVE3D_H
#define NGFC2SWEEPCURVE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2SweepCurve3d.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"

public ref class NGfc2SweepCurve3d: public NGfc2Curve3d
{
public:
    NGfc2SweepCurve3d();
    NGfc2SweepCurve3d(void* pEntity, bool bOwner);
    void setSpine3d(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    void setReferenceVector(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setSweepType(NGfc2SweepType nValue);
    NGfc2SweepType getSweepType();
    bool hasSweepType();

};
#endif
