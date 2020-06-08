#ifndef NGFC2POLYHEDRALFACE_H
#define NGFC2POLYHEDRALFACE_H

#include "NGfc2Topology.h"
#include "Gfc2PolyhedralFace.h"
#include "NGfc2PolyhedralLoop.h"
#include "NGfc2PlaneCoef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PolyhedralFace: public NGfc2Topology
{
public:
    NGfc2PolyhedralFace();
    NGfc2PolyhedralFace(void* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);
    NGfc2PolyhedralLoop^ getLoopsPtr(int nIndex);
    void setPlane(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlane();
    bool hasPlane();
    NGfc2PlaneCoef^ getPlanePtr();

};
#endif
