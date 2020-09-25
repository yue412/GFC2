#ifndef GFC2COMMONPOLYGONEX_H
#define GFC2COMMONPOLYGONEX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Polygon.h"
#include "GfcClasses/x3/Gfc2CoedgeListEx.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CommonPolygonEx: public Gfc2Polygon
{
GFCENGINE_DEC_OBJECT(Gfc2CommonPolygonEx, gfc::engine::CEntity)
public:
    Gfc2CommonPolygonEx();
    Gfc2CommonPolygonEx(bool bSetSchema);
    int getLoopExsCount() const;
    void clearLoopExs();
    void addLoopExs(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLoopExs(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2CoedgeListEx> getLoopExsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
