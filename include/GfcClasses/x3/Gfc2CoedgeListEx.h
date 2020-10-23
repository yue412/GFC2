#ifndef GFC2COEDGELISTEX_H
#define GFC2COEDGELISTEX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Topology.h"
#include "GfcClasses/x3/Gfc2Coedge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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
    std::shared_ptr<Gfc2Coedge> getCoedgeExsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
