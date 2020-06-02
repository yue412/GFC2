#ifndef GFC2SWEEP_H
#define GFC2SWEEP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Surface.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Sweep: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Sweep,gfc2::engine::EntityFactory)
public:
    Gfc2Sweep();
    Gfc2Sweep(bool bSetSchema);
    void setProfile(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getProfile() const;
    bool hasProfile() const;
    std::shared_ptr<Gfc2Curve2d> getProfilePtr();
    void setSpine3d(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSpine3d() const;
    bool hasSpine3d() const;
    std::shared_ptr<Gfc2Curve3d> getSpine3dPtr();
    void setReferenceVector(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getReferenceVector() const;
    bool hasReferenceVector() const;
    std::shared_ptr<Gfc2Vector3d> getReferenceVectorPtr();
    void setSweepType(const Gfc2SweepType& nValue);
    Gfc2SweepType getSweepType() const;
    bool hasSweepType() const;

};
#endif
