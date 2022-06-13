#ifndef NGFCCUBOIDBODY_H
#define NGFCCUBOIDBODY_H

#include "NGfcPrimitiveBody.h"
#include "GfcClasses\x3\GfcCuboidBody.h"
#include "NGfcCoordinates3d.h"
#include "NGfcVector3d.h"

public ref class NGfcCuboidBody: public NGfcPrimitiveBody
{
public:
    NGfcCuboidBody();
    NGfcCuboidBody(bool bNoCreate);
    void setCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoordinate();
    bool hasCoordinate();
    void setDimension(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDimension();
    bool hasDimension();

};
#endif
