#ifndef GFCBOX3D_H
#define GFCBOX3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBox3d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcBox3d, gfc::engine::CEntity)
public:
    GfcBox3d();
    GfcBox3d(bool bSetSchema);
    void setMin(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMin() const;
    bool hasMin() const;
    std::shared_ptr<GfcVector3d> getMinPtr();
    void setMax(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMax() const;
    bool hasMax() const;
    std::shared_ptr<GfcVector3d> getMaxPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
