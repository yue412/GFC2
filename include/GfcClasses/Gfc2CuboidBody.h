#ifndef GFC2CUBOIDBODY_H
#define GFC2CUBOIDBODY_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveBody.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CuboidBody: public Gfc2PrimitiveBody
{
GFCENGINE_DEC_OBJECT(Gfc2CuboidBody, gfc::engine::CEntity)
public:
    Gfc2CuboidBody();
    Gfc2CuboidBody(bool bSetSchema);
    void setCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    gfc::engine::CEntityWrapPtr<Gfc2Coordinates3d> getCoordinatePtr();
    void setDimension(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDimension() const;
    bool hasDimension() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getDimensionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
