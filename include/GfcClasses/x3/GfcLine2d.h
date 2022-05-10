#ifndef GFCLINE2D_H
#define GFCLINE2D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLine2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcLine2d, gfc::engine::CEntity)
public:
    GfcLine2d();
    GfcLine2d(bool bSetSchema);
    void setStartPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getStartPt() const;
    bool hasStartPt() const;
    std::shared_ptr<GfcVector2d> getStartPtPtr();
    void setEndPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndPt() const;
    bool hasEndPt() const;
    std::shared_ptr<GfcVector2d> getEndPtPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
