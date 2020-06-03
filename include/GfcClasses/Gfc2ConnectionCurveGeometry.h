#ifndef GFC2CONNECTIONCURVEGEOMETRY_H
#define GFC2CONNECTIONCURVEGEOMETRY_H

#include "GfcClasses.h"
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Curve3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ConnectionCurveGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionCurveGeometry, gfc::engine::Entity)
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
#endif
