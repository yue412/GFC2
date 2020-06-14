#ifndef GFC2COEDGELISTEX_H
#define GFC2COEDGELISTEX_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2Coedge.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CoedgeListEx: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2CoedgeListEx, gfc::engine::CEntity)
public:
    Gfc2CoedgeListEx();
    Gfc2CoedgeListEx(bool bSetSchema);
    int getCoedgeExsCount() const;
    void clearCoedgeExs();
    void addCoedgeExs(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoedgeExs(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Coedge> getCoedgeExsPtr(int nIndex);

};
#endif
