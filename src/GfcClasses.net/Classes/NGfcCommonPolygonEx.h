#ifndef NGFCCOMMONPOLYGONEX_H
#define NGFCCOMMONPOLYGONEX_H

#include "NGfcPolygon.h"
#include "GfcClasses\x3\GfcCommonPolygonEx.h"
#include "NGfcCoedgeListEx.h"

public ref class NGfcCommonPolygonEx: public NGfcPolygon
{
public:
    NGfcCommonPolygonEx();
    NGfcCommonPolygonEx(gfc::engine::CEntity* pEntity, bool bOwner);
    int getLoopExsCount();
    void clearLoopExs();
    void addLoopExs(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLoopExs(int nIndex);

};
#endif
