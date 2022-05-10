#ifndef GFCIMAGECURVE3D_H
#define GFCIMAGECURVE3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcImageCurve3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcImageCurve3d, gfc::engine::CEntity)
public:
    GfcImageCurve3d();
    GfcImageCurve3d(bool bSetSchema);
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve2d> getCurvePtr();
    void setSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurface() const;
    bool hasSurface() const;
    std::shared_ptr<GfcSurface> getSurfacePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
