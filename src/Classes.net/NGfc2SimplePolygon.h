#ifndef NGFC2SIMPLEPOLYGON_H
#define NGFC2SIMPLEPOLYGON_H

#include "NGfc2Polygon.h"
#include "GfcClasses\x3\Gfc2SimplePolygon.h"
#include "NGfc2SimpleLoop.h"

public ref class NGfc2SimplePolygon: public NGfc2Polygon
{
public:
    NGfc2SimplePolygon();
    NGfc2SimplePolygon(gfc::engine::CEntity* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);

};
#endif
