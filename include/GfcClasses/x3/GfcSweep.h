#ifndef GFCSWEEP_H
#define GFCSWEEP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSweep: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcSweep, gfc::engine::CEntity)
public:
    GfcSweep();
    GfcSweep(bool bSetSchema);
    void setProfile(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getProfile() const;
    bool hasProfile() const;
    std::shared_ptr<GfcCurve2d> getProfilePtr();
    void setSpine3d(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSpine3d() const;
    bool hasSpine3d() const;
    std::shared_ptr<GfcCurve3d> getSpine3dPtr();
    void setReferenceVector(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getReferenceVector() const;
    bool hasReferenceVector() const;
    std::shared_ptr<GfcVector3d> getReferenceVectorPtr();
    void setSweepType(const GfcSweepType& nValue);
    GfcSweepType getSweepType() const;
    bool hasSweepType() const;

};

GFCCLASSES_NAMESPACE_END

#endif
