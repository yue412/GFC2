#ifndef NGFC2COMMONPOLYGONEX_H
#define NGFC2COMMONPOLYGONEX_H

#include "NGfc2Polygon.h"
#include "Gfc2CommonPolygonEx.h"
#include "NGfc2CoedgeListEx.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CommonPolygonEx: public NGfc2Polygon
{
public:
    NGfc2CommonPolygonEx();
    NGfc2CommonPolygonEx(void* pEntity, bool bOwner);
    int getLoopExsCount();
    void clearLoopExs();
    void addLoopExs(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getLoopExs(int nIndex);
    NGfc2CoedgeListEx^ getLoopExsPtr(int nIndex);

};
#endif
