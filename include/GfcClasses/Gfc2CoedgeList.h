#ifndef GFC2COEDGELIST_H
#define GFC2COEDGELIST_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "Gfc2Curve2d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CoedgeList: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2CoedgeList,gfc2::engine::EntityFactory)
public:
    Gfc2CoedgeList();
    Gfc2CoedgeList(bool bSetSchema);
    int getCoedgesCount() const;
    void clearCoedges();
    void addCoedges(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoedges(int nIndex) const;
    std::shared_ptr<Gfc2Curve2d> getCoedgesPtr(int nIndex);

};
#endif
