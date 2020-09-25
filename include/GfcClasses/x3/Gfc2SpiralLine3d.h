#ifndef GFC2SPIRALLINE3D_H
#define GFC2SPIRALLINE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2Coordinates3d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SpiralLine3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2SpiralLine3d, gfc::engine::CEntity)
public:
    Gfc2SpiralLine3d();
    Gfc2SpiralLine3d(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    gfc::engine::CEntityWrapPtr<Gfc2Coordinates3d> getCoordPtr();
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangePtr();
    void setClockSign(const Gfc2Integer& nValue);
    Gfc2Integer getClockSign() const;
    bool hasClockSign() const;
    void setHeightCoef(const Gfc2Double& dValue);
    Gfc2Double getHeightCoef() const;
    bool hasHeightCoef() const;
    void setRadiusCoef(const Gfc2Double& dValue);
    Gfc2Double getRadiusCoef() const;
    bool hasRadiusCoef() const;

};

GFCCLASSES_NAMESPACE_END

#endif
