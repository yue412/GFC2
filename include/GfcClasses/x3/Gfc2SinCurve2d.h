#ifndef GFC2SINCURVE2D_H
#define GFC2SINCURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SinCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2SinCurve2d, gfc::engine::CEntity)
public:
    Gfc2SinCurve2d();
    Gfc2SinCurve2d(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<Gfc2Vector2d> getPosPtr();
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<Gfc2Vector2d> getDirXPtr();
    void setA(const Gfc2Double& dValue);
    Gfc2Double getA() const;
    bool hasA() const;
    void setB(const Gfc2Double& dValue);
    Gfc2Double getB() const;
    bool hasB() const;
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
