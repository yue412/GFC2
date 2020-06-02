#ifndef GFC2COEDGELISTEX_H
#define GFC2COEDGELISTEX_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "Gfc2Coedge.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CoedgeListEx: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2CoedgeListEx,gfc2::engine::EntityFactory)
public:
    Gfc2CoedgeListEx();
    Gfc2CoedgeListEx(bool bSetSchema);
    int getCoedgeExsCount() const;
    void clearCoedgeExs();
    void addCoedgeExs(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoedgeExs(int nIndex) const;
    std::shared_ptr<Gfc2Coedge> getCoedgeExsPtr(int nIndex);

};
#endif
