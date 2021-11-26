#ifndef NGFC2COMMONPOLYGONEX_H
#define NGFC2COMMONPOLYGONEX_H

#include "NGfc2Polygon.h"
#include "GfcClasses\x3\Gfc2CommonPolygonEx.h"
#include "NGfc2CoedgeListEx.h"

public ref class NGfc2CommonPolygonEx: public NGfc2Polygon
{
public:
    NGfc2CommonPolygonEx();
    NGfc2CommonPolygonEx(gfc::engine::CEntity* pEntity, bool bOwner);
    int getLoopExsCount();
    void clearLoopExs();
    void addLoopExs(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoopExs(int nIndex);

};
#endif
