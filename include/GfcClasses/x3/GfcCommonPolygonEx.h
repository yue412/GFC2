#ifndef GFCCOMMONPOLYGONEX_H
#define GFCCOMMONPOLYGONEX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcClasses/x3/GfcCoedgeListEx.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCommonPolygonEx: public GfcPolygon
{
GFCENGINE_DEC_OBJECT(GfcCommonPolygonEx, gfc::engine::CEntity)
public:
    GfcCommonPolygonEx();
    GfcCommonPolygonEx(bool bSetSchema);
    int getLoopExsCount() const;
    void clearLoopExs();
    void addLoopExs(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoopExs(int nIndex) const;
    std::shared_ptr<GfcCoedgeListEx> getLoopExsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
