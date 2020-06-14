#ifndef GFC2SINCURVE2D_H
#define GFC2SINCURVE2D_H

#include "GfcClasses.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SinCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2SinCurve2d, gfc::engine::CEntity)
public:
    Gfc2SinCurve2d();
    Gfc2SinCurve2d(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector2d> getPosPtr();
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector2d> getDirXPtr();
    void setA(const Gfc2Double& dValue);
    Gfc2Double getA() const;
    bool hasA() const;
    void setB(const Gfc2Double& dValue);
    Gfc2Double getB() const;
    bool hasB() const;
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangePtr();
    void setClockSign(const Gfc2Integer& nValue);
    Gfc2Integer getClockSign() const;
    bool hasClockSign() const;

};
#endif
