#ifndef GFCSINCURVE2D_H
#define GFCSINCURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSinCurve2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcSinCurve2d, gfc::engine::CEntity)
public:
    GfcSinCurve2d();
    GfcSinCurve2d(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<GfcVector2d> getPosPtr();
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<GfcVector2d> getDirXPtr();
    void setA(const GfcDouble& dValue);
    GfcDouble getA() const;
    bool hasA() const;
    void setB(const GfcDouble& dValue);
    GfcDouble getB() const;
    bool hasB() const;
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
