#ifndef NGFCPOLYHEDRALFACE_H
#define NGFCPOLYHEDRALFACE_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcPolyhedralFace.h"
#include "NGfcPolyhedralLoop.h"
#include "NGfcPlaneCoef.h"

public ref class NGfcPolyhedralFace: public NGfcTopology
{
public:
    NGfcPolyhedralFace();
    NGfcPolyhedralFace(gfc::engine::CEntity* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);
    void setPlane(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlane();
    bool hasPlane();

};
#endif
