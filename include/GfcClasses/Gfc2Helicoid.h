#ifndef GFC2HELICOID_H
#define GFC2HELICOID_H

#include "GfcClasses.h"
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Helicoid: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Helicoid, gfc::engine::CEntity)
public:
    Gfc2Helicoid();
    Gfc2Helicoid(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    gfc::engine::CEntityWrapPtr<Gfc2Coordinates3d> getCoordPtr();
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangeVPtr();
    void setClockSign(const Gfc2Integer& nValue);
    Gfc2Integer getClockSign() const;
    bool hasClockSign() const;
    void setHeightCoef(const Gfc2Double& dValue);
    Gfc2Double getHeightCoef() const;
    bool hasHeightCoef() const;
    void setRadiusCoef(const Gfc2Double& dValue);
    Gfc2Double getRadiusCoef() const;
    bool hasRadiusCoef() const;
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve2d> getCurvePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
