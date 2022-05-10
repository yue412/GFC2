#ifndef GFCCOEDGELIST_H
#define GFCCOEDGELIST_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCoedgeList: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcCoedgeList, gfc::engine::CEntity)
public:
    GfcCoedgeList();
    GfcCoedgeList(bool bSetSchema);
    int getCoedgesCount() const;
    void clearCoedges();
    void addCoedges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoedges(int nIndex) const;
    std::shared_ptr<GfcCurve2d> getCoedgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
