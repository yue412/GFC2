#ifndef GFCHELICOID_H
#define GFCHELICOID_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcHelicoid: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcHelicoid, gfc::engine::CEntity)
public:
    GfcHelicoid();
    GfcHelicoid(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<GfcCoordinates3d> getCoordPtr();
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();
    void setClockSign(const GfcInteger& nValue);
    GfcInteger getClockSign() const;
    bool hasClockSign() const;
    void setHeightCoef(const GfcDouble& dValue);
    GfcDouble getHeightCoef() const;
    bool hasHeightCoef() const;
    void setRadiusCoef(const GfcDouble& dValue);
    GfcDouble getRadiusCoef() const;
    bool hasRadiusCoef() const;
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve2d> getCurvePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
