#ifndef GFC2COMMONPOLYGON_H
#define GFC2COMMONPOLYGON_H

#include "GfcClasses.h"
#include "Gfc2Polygon.h"
#include "Gfc2CoedgeList.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CommonPolygon: public Gfc2Polygon
{
GFCENGINE_DEC_OBJECT(Gfc2CommonPolygon, gfc::engine::Entity)
public:
    Gfc2CommonPolygon();
    Gfc2CommonPolygon(bool bSetSchema);
    int getLoopsCount() const;
    void clearLoops();
    void addLoops(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoops(int nIndex) const;
    std::shared_ptr<Gfc2CoedgeList> getLoopsPtr(int nIndex);

};
#endif
