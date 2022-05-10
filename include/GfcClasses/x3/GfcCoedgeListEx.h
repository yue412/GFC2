#ifndef GFCCOEDGELISTEX_H
#define GFCCOEDGELISTEX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcCoedge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCoedgeListEx: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcCoedgeListEx, gfc::engine::CEntity)
public:
    GfcCoedgeListEx();
    GfcCoedgeListEx(bool bSetSchema);
    int getCoedgeExsCount() const;
    void clearCoedgeExs();
    void addCoedgeExs(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoedgeExs(int nIndex) const;
    std::shared_ptr<GfcCoedge> getCoedgeExsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
