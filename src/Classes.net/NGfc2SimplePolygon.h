#ifndef NGFC2SIMPLEPOLYGON_H
#define NGFC2SIMPLEPOLYGON_H

#include "NGfc2Polygon.h"
#include "Gfc2SimplePolygon.h"
#include "NGfc2SimpleLoop.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SimplePolygon: public NGfc2Polygon
{
public:
    NGfc2SimplePolygon();
    NGfc2SimplePolygon(void* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLoops(int nIndex);
    NGfc2SimpleLoop^ getLoopsPtr(int nIndex);

};
#endif
