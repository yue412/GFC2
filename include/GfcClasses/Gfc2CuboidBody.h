#ifndef GFC2CUBOIDBODY_H
#define GFC2CUBOIDBODY_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveBody.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CuboidBody: public Gfc2PrimitiveBody
{
GFCENGINE_DEC_OBJECT(Gfc2CuboidBody, gfc2::engine::Entity)
public:
    Gfc2CuboidBody();
    Gfc2CuboidBody(bool bSetSchema);
    void setCoordinate(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    std::shared_ptr<Gfc2Coordinates3d> getCoordinatePtr();
    void setDimension(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDimension() const;
    bool hasDimension() const;
    std::shared_ptr<Gfc2Vector3d> getDimensionPtr();

};
#endif
