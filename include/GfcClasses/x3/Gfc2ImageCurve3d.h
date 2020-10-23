#ifndef GFC2IMAGECURVE3D_H
#define GFC2IMAGECURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ImageCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2ImageCurve3d, gfc::engine::CEntity)
public:
    Gfc2ImageCurve3d();
    Gfc2ImageCurve3d(bool bSetSchema);
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve2d> getCurvePtr();
    void setSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurface() const;
    bool hasSurface() const;
    std::shared_ptr<Gfc2Surface> getSurfacePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
