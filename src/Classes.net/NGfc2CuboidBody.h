#ifndef NGFC2CUBOIDBODY_H
#define NGFC2CUBOIDBODY_H

#include "NGfc2PrimitiveBody.h"
#include "Gfc2CuboidBody.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CuboidBody: public NGfc2PrimitiveBody
{
public:
    NGfc2CuboidBody();
    NGfc2CuboidBody(void* pEntity, bool bOwner);
    void setCoordinate(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCoordinate();
    bool hasCoordinate();
    NGfc2Coordinates3d^ getCoordinatePtr();
    void setDimension(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDimension();
    bool hasDimension();
    NGfc2Vector3d^ getDimensionPtr();

};
#endif
