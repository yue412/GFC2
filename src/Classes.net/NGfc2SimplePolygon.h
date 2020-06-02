#ifndef NGFC2SIMPLEPOLYGON_H
#define NGFC2SIMPLEPOLYGON_H

#include "NGfc2Polygon.h"
#include "Gfc2SimplePolygon.h"
#include "NGfc2SimpleLoop.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SimplePolygon: public NGfc2Polygon
{
public:
    NGfc2SimplePolygon();
    NGfc2SimplePolygon(void* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getLoops(int nIndex);
    NGfc2SimpleLoop^ getLoopsPtr(int nIndex);

};
#endif
