#ifndef GFC2IMAGECURVE3D_H
#define GFC2IMAGECURVE3D_H

#include "GfcClasses.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Surface.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ImageCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2ImageCurve3d, gfc::engine::Entity)
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
#endif
