#ifndef GFC2CONNECTIONCURVEGEOMETRY_H
#define GFC2CONNECTIONCURVEGEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ConnectionGeometry.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ConnectionCurveGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionCurveGeometry, gfc::engine::CEntity)
public:
    Gfc2ConnectionCurveGeometry();
    Gfc2ConnectionCurveGeometry(bool bSetSchema);
    void setCurveOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurveOnRelatingElement() const;
    bool hasCurveOnRelatingElement() const;
    std::shared_ptr<Gfc2Curve3d> getCurveOnRelatingElementPtr();
    void setCurveOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurveOnRelatedElement() const;
    bool hasCurveOnRelatedElement() const;
    std::shared_ptr<Gfc2Curve3d> getCurveOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
