#ifndef NGFC2GEOMETRYSHAPE_H
#define NGFC2GEOMETRYSHAPE_H

#include "NGfc2Shape.h"
#include "Gfc2GeometryShape.h"
#include "NGfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2GeometryShape: public NGfc2Shape
{
public:
    NGfc2GeometryShape();
    NGfc2GeometryShape(void* pEntity, bool bOwner);
    void setGeo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getGeo();
    bool hasGeo();
    NGfc2Geometry^ getGeoPtr();

};
#endif
