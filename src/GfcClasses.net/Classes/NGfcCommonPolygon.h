#ifndef NGFCCOMMONPOLYGON_H
#define NGFCCOMMONPOLYGON_H

#include "NGfcPolygon.h"
#include "GfcClasses\x3\GfcCommonPolygon.h"
#include "NGfcCoedgeList.h"

public ref class NGfcCommonPolygon: public NGfcPolygon
{
public:
    NGfcCommonPolygon();
    NGfcCommonPolygon(gfc::engine::CEntity* pEntity, bool bOwner);
    int getLoopsCount();
    void clearLoops();
    void addLoops(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoops(int nIndex);

};
#endif
