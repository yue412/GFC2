#ifndef NGFC2SWEEPCURVE3D_H
#define NGFC2SWEEPCURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2SweepCurve3d.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SweepCurve3d: public NGfc2Curve3d
{
public:
    NGfc2SweepCurve3d();
    NGfc2SweepCurve3d(void* pEntity, bool bOwner);
    void setSpine3d(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    NGfc2Curve3d^ getSpine3dPtr();
    void setReferenceVector(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    NGfc2Vector3d^ getReferenceVectorPtr();
    void setPoint(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector2d^ getPointPtr();
    void setSweepType(NGfc2SweepType nValue);
    NGfc2SweepType getSweepType();
    bool hasSweepType();

};
#endif
