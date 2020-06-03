#ifndef GFC2BOX3D_H
#define GFC2BOX3D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Box3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Box3d, gfc2::engine::Entity)
public:
    Gfc2Box3d();
    Gfc2Box3d(bool bSetSchema);
    void setMin(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMin() const;
    bool hasMin() const;
    std::shared_ptr<Gfc2Vector3d> getMinPtr();
    void setMax(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMax() const;
    bool hasMax() const;
    std::shared_ptr<Gfc2Vector3d> getMaxPtr();

};
#endif
