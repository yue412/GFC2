#ifndef GFC2NURBSCTRLPT2D_H
#define GFC2NURBSCTRLPT2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2NurbsCtrlPt2d: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2NurbsCtrlPt2d, gfc::engine::CEntity)
public:
    Gfc2NurbsCtrlPt2d();
    Gfc2NurbsCtrlPt2d(bool bSetSchema);
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<Gfc2Vector2d> getPointPtr();
    void setWeight(const Gfc2Double& dValue);
    Gfc2Double getWeight() const;
    bool hasWeight() const;

};

GFCCLASSES_NAMESPACE_END

#endif
