#ifndef GFC2VECTOR3D_H
#define GFC2VECTOR3D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Vector3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Vector3d,gfc2::engine::EntityFactory)
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
#endif
