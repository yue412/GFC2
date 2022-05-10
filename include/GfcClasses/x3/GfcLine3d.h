#ifndef GFCLINE3D_H
#define GFCLINE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLine3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcLine3d, gfc::engine::CEntity)
public:
    GfcLine3d();
    GfcLine3d(bool bSetSchema);
    void setStartPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getStartPt() const;
    bool hasStartPt() const;
    std::shared_ptr<GfcVector3d> getStartPtPtr();
    void setEndPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndPt() const;
    bool hasEndPt() const;
    std::shared_ptr<GfcVector3d> getEndPtPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
