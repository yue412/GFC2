#ifndef GFC2ELLIPSE2D_H
#define GFC2ELLIPSE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Ellipse2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2Ellipse2d, gfc::engine::CEntity)
public:
    Gfc2Ellipse2d();
    Gfc2Ellipse2d(bool bSetSchema);
    void setCenterPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCenterPt() const;
    bool hasCenterPt() const;
    std::shared_ptr<Gfc2Vector2d> getCenterPtPtr();
    void setMajorAxis(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMajorAxis() const;
    bool hasMajorAxis() const;
    std::shared_ptr<Gfc2Vector2d> getMajorAxisPtr();
    void setdMajorRad(const Gfc2Double& dValue);
    Gfc2Double getdMajorRad() const;
    bool hasdMajorRad() const;
    void setdMinorRad(const Gfc2Double& dValue);
    Gfc2Double getdMinorRad() const;
    bool hasdMinorRad() const;
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<Gfc2Intervald> getRangePtr();
    void setClockSign(const Gfc2Integer& nValue);
    Gfc2Integer getClockSign() const;
    bool hasClockSign() const;

};

GFCCLASSES_NAMESPACE_END

#endif
