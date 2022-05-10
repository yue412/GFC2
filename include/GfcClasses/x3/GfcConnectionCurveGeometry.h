#ifndef GFCCONNECTIONCURVEGEOMETRY_H
#define GFCCONNECTIONCURVEGEOMETRY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcConnectionGeometry.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConnectionCurveGeometry: public GfcConnectionGeometry
{
GFCENGINE_DEC_OBJECT(GfcConnectionCurveGeometry, gfc::engine::CEntity)
public:
    GfcConnectionCurveGeometry();
    GfcConnectionCurveGeometry(bool bSetSchema);
    void setCurveOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurveOnRelatingElement() const;
    bool hasCurveOnRelatingElement() const;
    std::shared_ptr<GfcCurve3d> getCurveOnRelatingElementPtr();
    void setCurveOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurveOnRelatedElement() const;
    bool hasCurveOnRelatedElement() const;
    std::shared_ptr<GfcCurve3d> getCurveOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
