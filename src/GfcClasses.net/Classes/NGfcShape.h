#ifndef NGFCSHAPE_H
#define NGFCSHAPE_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcShape.h"
#include "NGfcCoordinates3d.h"
#include "NGfcBox3d.h"

public ref class NGfcShape: public NEntity
{
public:
    NGfcShape();
    NGfcShape(bool bNoCreate);
    void setLocalCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLocalCoordinate();
    bool hasLocalCoordinate();
    void setBoundingBox(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBoundingBox();
    bool hasBoundingBox();

};
#endif
