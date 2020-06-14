#ifndef GFC2POLYHEDRALFACE_H
#define GFC2POLYHEDRALFACE_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2PolyhedralLoop.h"
#include "Gfc2PlaneCoef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PolyhedralFace: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralFace, gfc::engine::CEntity)
public:
    Gfc2PolyhedralFace();
    Gfc2PolyhedralFace(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2PolyhedralLoop> getLoopsPtr(int nIndex);
    void setPlane(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    gfc::engine::CEntityWrapPtr<Gfc2PlaneCoef> getPlanePtr();

};
#endif
