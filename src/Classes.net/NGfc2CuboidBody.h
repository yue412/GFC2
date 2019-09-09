#ifndef NGFC2CUBOIDBODY_H
#define NGFC2CUBOIDBODY_H

#include "NGfc2Body.h"
#include "Gfc2CuboidBody.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CuboidBody: public NGfc2Body
{
public:
    NGfc2CuboidBody();
    NGfc2CuboidBody(void* pEntity, bool bOwner);
    void setCoordinate(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoordinate();
    bool hasCoordinate();
    NGfc2Coordinates3d^ getCoordinatePtr();
    void setDimension(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDimension();
    bool hasDimension();
    NGfc2Vector3d^ getDimensionPtr();

};
#endif
