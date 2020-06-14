#ifndef GFC2SWEEPCURVE3D_H
#define GFC2SWEEPCURVE3D_H

#include "GfcClasses.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector2d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SweepCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2SweepCurve3d, gfc::engine::CEntity)
public:
    Gfc2SweepCurve3d();
    Gfc2SweepCurve3d(bool bSetSchema);
    void setSpine3d(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSpine3d() const;
    bool hasSpine3d() const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve3d> getSpine3dPtr();
    void setReferenceVector(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferenceVector() const;
    bool hasReferenceVector() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getReferenceVectorPtr();
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector2d> getPointPtr();
    void setSweepType(const Gfc2SweepType& nValue);
    Gfc2SweepType getSweepType() const;
    bool hasSweepType() const;

};
#endif
