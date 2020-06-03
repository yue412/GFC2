#ifndef GFC2COMMONPOLYGONEX_H
#define GFC2COMMONPOLYGONEX_H

#include "GfcClasses.h"
#include "Gfc2Polygon.h"
#include "Gfc2CoedgeListEx.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CommonPolygonEx: public Gfc2Polygon
{
GFCENGINE_DEC_OBJECT(Gfc2CommonPolygonEx, gfc::engine::Entity)
public:
    Gfc2CommonPolygonEx();
    Gfc2CommonPolygonEx(bool bSetSchema);
    int getLoopExsCount() const;
    void clearLoopExs();
    void addLoopExs(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoopExs(int nIndex) const;
    std::shared_ptr<Gfc2CoedgeListEx> getLoopExsPtr(int nIndex);

};
#endif
