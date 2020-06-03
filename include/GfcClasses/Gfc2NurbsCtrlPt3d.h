#ifndef GFC2NURBSCTRLPT3D_H
#define GFC2NURBSCTRLPT3D_H

#include "GfcClasses.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2NurbsCtrlPt3d: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2NurbsCtrlPt3d, gfc2::engine::Entity)
public:
    Gfc2NurbsCtrlPt3d();
    Gfc2NurbsCtrlPt3d(bool bSetSchema);
    void setPoint(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<Gfc2Vector3d> getPointPtr();
    void setWeight(const Gfc2Double& dValue);
    Gfc2Double getWeight() const;
    bool hasWeight() const;

};
#endif
