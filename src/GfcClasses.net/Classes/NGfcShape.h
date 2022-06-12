#ifndef NGFCSHAPE_H
#define NGFCSHAPE_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcShape.h"
#include "NGfcCoordinates3d.h"
#include "NGfcBox3d.h"

public ref class NGfcShape: public NGfcEntity
{
public:
    NGfcShape();
    NGfcShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setLocalCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLocalCoordinate();
    bool hasLocalCoordinate();
    void setBoundingBox(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBoundingBox();
    bool hasBoundingBox();

};
#endif
