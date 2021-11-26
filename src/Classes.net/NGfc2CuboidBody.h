#ifndef NGFC2CUBOIDBODY_H
#define NGFC2CUBOIDBODY_H

#include "NGfc2PrimitiveBody.h"
#include "GfcClasses\x3\Gfc2CuboidBody.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2CuboidBody: public NGfc2PrimitiveBody
{
public:
    NGfc2CuboidBody();
    NGfc2CuboidBody(void* pEntity, bool bOwner);
    void setCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoordinate();
    bool hasCoordinate();
    void setDimension(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDimension();
    bool hasDimension();

};
#endif
