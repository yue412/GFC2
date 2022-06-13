#ifndef NGFCBOX3D_H
#define NGFCBOX3D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcBox3d.h"
#include "NGfcVector3d.h"

public ref class NGfcBox3d: public NGfcGeometry
{
public:
    NGfcBox3d();
    NGfcBox3d(bool bNoCreate);
    void setMin(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMin();
    bool hasMin();
    void setMax(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMax();
    bool hasMax();

};
#endif
