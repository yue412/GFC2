#ifndef GFCPOLYHEDRALFACE_H
#define GFCPOLYHEDRALFACE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcPolyhedralLoop.h"
#include "GfcClasses/x3/GfcPlaneCoef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPolyhedralFace: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcPolyhedralFace, gfc::engine::CEntity)
public:
    GfcPolyhedralFace();
    GfcPolyhedralFace(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<GfcPolyhedralLoop> getLoopsPtr(int nIndex);
    void setPlane(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    std::shared_ptr<GfcPlaneCoef> getPlanePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
