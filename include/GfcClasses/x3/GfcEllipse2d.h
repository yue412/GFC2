#ifndef GFCELLIPSE2D_H
#define GFCELLIPSE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEllipse2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcEllipse2d, gfc::engine::CEntity)
public:
    GfcEllipse2d();
    GfcEllipse2d(bool bSetSchema);
    void setCenterPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCenterPt() const;
    bool hasCenterPt() const;
    std::shared_ptr<GfcVector2d> getCenterPtPtr();
    void setMajorAxis(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMajorAxis() const;
    bool hasMajorAxis() const;
    std::shared_ptr<GfcVector2d> getMajorAxisPtr();
    void setdMajorRad(const GfcDouble& dValue);
    GfcDouble getdMajorRad() const;
    bool hasdMajorRad() const;
    void setdMinorRad(const GfcDouble& dValue);
    GfcDouble getdMinorRad() const;
    bool hasdMinorRad() const;
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<GfcIntervald> getRangePtr();
    void setClockSign(const GfcInteger& nValue);
    GfcInteger getClockSign() const;
    bool hasClockSign() const;

};

GFCCLASSES_NAMESPACE_END

#endif
