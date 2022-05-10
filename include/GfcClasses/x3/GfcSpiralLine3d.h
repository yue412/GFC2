#ifndef GFCSPIRALLINE3D_H
#define GFCSPIRALLINE3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSpiralLine3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcSpiralLine3d, gfc::engine::CEntity)
public:
    GfcSpiralLine3d();
    GfcSpiralLine3d(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<GfcCoordinates3d> getCoordPtr();
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
    void setHeightCoef(const GfcDouble& dValue);
    GfcDouble getHeightCoef() const;
    bool hasHeightCoef() const;
    void setRadiusCoef(const GfcDouble& dValue);
    GfcDouble getRadiusCoef() const;
    bool hasRadiusCoef() const;

};

GFCCLASSES_NAMESPACE_END

#endif
