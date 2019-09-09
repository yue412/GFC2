#ifndef NGFC2COMMONPOLYGONEX_H
#define NGFC2COMMONPOLYGONEX_H

#include "NGfc2Polygon.h"
#include "Gfc2CommonPolygonEx.h"
#include "NGfc2CoedgeListEx.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CommonPolygonEx: public NGfc2Polygon
{
public:
    NGfc2CommonPolygonEx();
    NGfc2CommonPolygonEx(void* pEntity, bool bOwner);
    int getLoopExsCount();
    void clearLoopExs();
    void addLoopExs(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLoopExs(int nIndex);
    NGfc2CoedgeListEx^ getLoopExsPtr(int nIndex);

};
#endif
