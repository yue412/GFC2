#ifndef GFC2SPIRALLINE2D_H
#define GFC2SPIRALLINE2D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Coordinates2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SpiralLine2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2SpiralLine2d,gfc2::engine::EntityFactory)
public:
    Gfc2SpiralLine2d();
    Gfc2SpiralLine2d(bool bSetSchema);
    void setCoord(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<Gfc2Coordinates2d> getCoordPtr();
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setRange(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<Gfc2Intervald> getRangePtr();
    void setClockSign(const Gfc2Integer& nValue);
    Gfc2Integer getClockSign() const;
    bool hasClockSign() const;
    void setRadiusCoef(const Gfc2Double& dValue);
    Gfc2Double getRadiusCoef() const;
    bool hasRadiusCoef() const;

};
#endif
