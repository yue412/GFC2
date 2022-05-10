#ifndef GFCCOMMONPOLYGON_H
#define GFCCOMMONPOLYGON_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcClasses/x3/GfcCoedgeList.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCommonPolygon: public GfcPolygon
{
GFCENGINE_DEC_OBJECT(GfcCommonPolygon, gfc::engine::CEntity)
public:
    GfcCommonPolygon();
    GfcCommonPolygon(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<GfcCoedgeList> getLoopsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
