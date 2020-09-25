#ifndef GFC2COEDGELIST_H
#define GFC2COEDGELIST_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Topology.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CoedgeList: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2CoedgeList, gfc::engine::CEntity)
public:
    Gfc2CoedgeList();
    Gfc2CoedgeList(bool bSetSchema);
    int getCoedgesCount() const;
    void clearCoedges();
    void addCoedges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoedges(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve2d> getCoedgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
