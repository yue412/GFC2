#ifndef NGFC2GEOMETRYSHAPE_H
#define NGFC2GEOMETRYSHAPE_H

#include "NGfc2Shape.h"
#include "GfcClasses\x3\Gfc2GeometryShape.h"
#include "NGfc2Geometry.h"

public ref class NGfc2GeometryShape: public NGfc2Shape
{
public:
    NGfc2GeometryShape();
    NGfc2GeometryShape(gfc::engine::CEntity* pEntity, bool bOwner);
    int getGeosCount();
    void clearGeos();
    void addGeos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getGeos(int nIndex);

};
#endif
