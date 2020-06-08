#ifndef GFC2PREIMAGECURVE2D_H
#define GFC2PREIMAGECURVE2D_H

#include "GfcClasses.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Surface.h"
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PreimageCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2PreimageCurve2d, gfc::engine::CEntity)
public:
    Gfc2PreimageCurve2d();
    Gfc2PreimageCurve2d(bool bSetSchema);
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<Gfc2Intervald> getRangePtr();
    void setReversed(const Gfc2Boolean& bValue);
    Gfc2Boolean getReversed() const;
    bool hasReversed() const;
    void setBase(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBase() const;
    bool hasBase() const;
    std::shared_ptr<Gfc2Surface> getBasePtr();
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve3d> getCurvePtr();
    void setTolerance(const Gfc2Double& dValue);
    Gfc2Double getTolerance() const;
    bool hasTolerance() const;

};
#endif
