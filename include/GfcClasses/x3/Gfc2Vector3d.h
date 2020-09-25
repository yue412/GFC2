#ifndef GFC2VECTOR3D_H
#define GFC2VECTOR3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Vector3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Vector3d, gfc::engine::CEntity)
public:
    Gfc2Vector3d();
    Gfc2Vector3d(bool bSetSchema);
    void setX(const Gfc2Double& dValue);
    Gfc2Double getX() const;
    bool hasX() const;
    void setY(const Gfc2Double& dValue);
    Gfc2Double getY() const;
    bool hasY() const;
    void setZ(const Gfc2Double& dValue);
    Gfc2Double getZ() const;
    bool hasZ() const;

};

GFCCLASSES_NAMESPACE_END

#endif
