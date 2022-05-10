#ifndef GFCNURBSCTRLPT3D_H
#define GFCNURBSCTRLPT3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcNurbsCtrlPt3d: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcNurbsCtrlPt3d, gfc::engine::CEntity)
public:
    GfcNurbsCtrlPt3d();
    GfcNurbsCtrlPt3d(bool bSetSchema);
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<GfcVector3d> getPointPtr();
    void setWeight(const GfcDouble& dValue);
    GfcDouble getWeight() const;
    bool hasWeight() const;

};

GFCCLASSES_NAMESPACE_END

#endif
