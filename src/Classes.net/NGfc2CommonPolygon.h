#ifndef NGFC2COMMONPOLYGON_H
#define NGFC2COMMONPOLYGON_H

#include "NGfc2Polygon.h"
#include "GfcClasses\x3\Gfc2CommonPolygon.h"
#include "NGfc2CoedgeList.h"

public ref class NGfc2CommonPolygon: public NGfc2Polygon
{
public:
    NGfc2CommonPolygon();
    NGfc2CommonPolygon(void* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);

};
#endif
