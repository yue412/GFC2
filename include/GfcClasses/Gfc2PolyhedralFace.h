#ifndef GFC2POLYHEDRALFACE_H
#define GFC2POLYHEDRALFACE_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2PolyhedralLoop.h"
#include "Gfc2PlaneCoef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PolyhedralFace: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedralFace, gfc2::engine::Entity)
public:
    Gfc2PolyhedralFace();
    Gfc2PolyhedralFace(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<Gfc2PolyhedralLoop> getLoopsPtr(int nIndex);
    void setPlane(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    std::shared_ptr<Gfc2PlaneCoef> getPlanePtr();

};
#endif
