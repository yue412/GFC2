#ifndef NGFC2COMMONPOLYGON_H
#define NGFC2COMMONPOLYGON_H

#include "NGfc2Polygon.h"
#include "Gfc2CommonPolygon.h"
#include "NGfc2CoedgeList.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CommonPolygon: public NGfc2Polygon
{
public:
    NGfc2CommonPolygon();
    NGfc2CommonPolygon(void* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLoops(int nIndex);
    NGfc2CoedgeList^ getLoopsPtr(int nIndex);

};
#endif
