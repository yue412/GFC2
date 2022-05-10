#ifndef GFCNURBSCTRLPT2D_H
#define GFCNURBSCTRLPT2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcNurbsCtrlPt2d: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcNurbsCtrlPt2d, gfc::engine::CEntity)
public:
    GfcNurbsCtrlPt2d();
    GfcNurbsCtrlPt2d(bool bSetSchema);
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<GfcVector2d> getPointPtr();
    void setWeight(const GfcDouble& dValue);
    GfcDouble getWeight() const;
    bool hasWeight() const;

};

GFCCLASSES_NAMESPACE_END

#endif
