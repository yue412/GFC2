#ifndef NGFCGEOMETRYSHAPE_H
#define NGFCGEOMETRYSHAPE_H

#include "NGfcShape.h"
#include "GfcClasses\x3\GfcGeometryShape.h"
#include "NGfcGeometry.h"

public ref class NGfcGeometryShape: public NGfcShape
{
public:
    NGfcGeometryShape();
    NGfcGeometryShape(bool bNoCreate);
    int getGeosCount();
    void clearGeos();
    void addGeos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getGeos(int nIndex);

};
#endif
