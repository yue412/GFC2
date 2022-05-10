#ifndef GFCSIMPLEPOLYGON_H
#define GFCSIMPLEPOLYGON_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcClasses/x3/GfcSimpleLoop.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSimplePolygon: public GfcPolygon
{
GFCENGINE_DEC_OBJECT(GfcSimplePolygon, gfc::engine::CEntity)
public:
    GfcSimplePolygon();
    GfcSimplePolygon(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<GfcSimpleLoop> getLoopsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
