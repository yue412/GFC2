#ifndef GFCSWEEPCURVE3D_H
#define GFCSWEEPCURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSweepCurve3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcSweepCurve3d, gfc::engine::CEntity)
public:
    GfcSweepCurve3d();
    GfcSweepCurve3d(bool bSetSchema);
    void setSpine3d(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSpine3d() const;
    bool hasSpine3d() const;
    std::shared_ptr<GfcCurve3d> getSpine3dPtr();
    void setReferenceVector(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferenceVector() const;
    bool hasReferenceVector() const;
    std::shared_ptr<GfcVector3d> getReferenceVectorPtr();
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<GfcVector2d> getPointPtr();
    void setSweepType(const GfcSweepType& nValue);
    GfcSweepType getSweepType() const;
    bool hasSweepType() const;

};

GFCCLASSES_NAMESPACE_END

#endif
