#ifndef GFC2COMMONPOLYGON_H
#define GFC2COMMONPOLYGON_H

#include "GfcClasses.h"
#include "Gfc2Polygon.h"
#include "Gfc2CoedgeList.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CommonPolygon: public Gfc2Polygon
{
GFCENGINE_DEC_OBJECT(Gfc2CommonPolygon, gfc::engine::CEntity)
public:
    Gfc2CommonPolygon();
    Gfc2CommonPolygon(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2CoedgeList> getLoopsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
