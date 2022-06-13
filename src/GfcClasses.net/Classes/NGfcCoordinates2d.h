#ifndef NGFCCOORDINATES2D_H
#define NGFCCOORDINATES2D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcCoordinates2d.h"
#include "NGfcVector2d.h"

public ref class NGfcCoordinates2d: public NGfcGeometry
{
public:
    NGfcCoordinates2d();
    NGfcCoordinates2d(bool bNoCreate);
    void setOrigin(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOrigin();
    bool hasOrigin();
    void setX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getX();
    bool hasX();
    void setY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getY();
    bool hasY();

};
#endif
