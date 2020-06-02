#ifndef GFC2ARC2D_H
#define GFC2ARC2D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Arc2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2Arc2d,gfc2::engine::EntityFactory)
public:
    Gfc2Arc2d();
    Gfc2Arc2d(bool bSetSchema);
    void setCenterPt(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCenterPt() const;
    bool hasCenterPt() const;
    std::shared_ptr<Gfc2Vector2d> getCenterPtPtr();
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

};
#endif
