#ifndef GFCSPIRALLINE2D_H
#define GFCSPIRALLINE2D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcCoordinates2d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSpiralLine2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcSpiralLine2d, gfc::engine::CEntity)
public:
    GfcSpiralLine2d();
    GfcSpiralLine2d(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<GfcCoordinates2d> getCoordPtr();
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<GfcIntervald> getRangePtr();
    void setClockSign(const GfcInteger& nValue);
    GfcInteger getClockSign() const;
    bool hasClockSign() const;
    void setRadiusCoef(const GfcDouble& dValue);
    GfcDouble getRadiusCoef() const;
    bool hasRadiusCoef() const;

};

GFCCLASSES_NAMESPACE_END

#endif
