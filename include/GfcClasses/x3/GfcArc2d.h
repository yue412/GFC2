#ifndef GFCARC2D_H
#define GFCARC2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcArc2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcArc2d, gfc::engine::CEntity)
public:
    GfcArc2d();
    GfcArc2d(bool bSetSchema);
    void setCenterPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCenterPt() const;
    bool hasCenterPt() const;
    std::shared_ptr<GfcVector2d> getCenterPtPtr();
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

};

GFCCLASSES_NAMESPACE_END

#endif
