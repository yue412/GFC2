#ifndef GFCPOLYHEDRALLOOP_H
#define GFCPOLYHEDRALLOOP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcPolyhedralEdge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPolyhedralLoop: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcPolyhedralLoop, gfc::engine::CEntity)
public:
    GfcPolyhedralLoop();
    GfcPolyhedralLoop(bool bSetSchema);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEdges(int nIndex) const;
    std::shared_ptr<GfcPolyhedralEdge> getEdgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
