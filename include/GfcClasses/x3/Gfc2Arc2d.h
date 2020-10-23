#ifndef GFC2ARC2D_H
#define GFC2ARC2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Arc2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2Arc2d, gfc::engine::CEntity)
public:
    Gfc2Arc2d();
    Gfc2Arc2d(bool bSetSchema);
    void setCenterPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCenterPt() const;
    bool hasCenterPt() const;
    std::shared_ptr<Gfc2Vector2d> getCenterPtPtr();
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
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
