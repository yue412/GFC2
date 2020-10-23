#ifndef GFC2SIMPLEPOLYGON_H
#define GFC2SIMPLEPOLYGON_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Polygon.h"
#include "GfcClasses/x3/Gfc2SimpleLoop.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SimplePolygon: public Gfc2Polygon
{
GFCENGINE_DEC_OBJECT(Gfc2SimplePolygon, gfc::engine::CEntity)
public:
    Gfc2SimplePolygon();
    Gfc2SimplePolygon(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<Gfc2SimpleLoop> getLoopsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
