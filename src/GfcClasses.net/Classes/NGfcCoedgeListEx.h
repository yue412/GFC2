#ifndef NGFCCOEDGELISTEX_H
#define NGFCCOEDGELISTEX_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcCoedgeListEx.h"
#include "NGfcCoedge.h"

public ref class NGfcCoedgeListEx: public NGfcTopology
{
public:
    NGfcCoedgeListEx();
    NGfcCoedgeListEx(gfc::engine::CEntity* pEntity, bool bOwner);
    int getCoedgeExsCount();
    void clearCoedgeExs();
    void addCoedgeExs(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoedgeExs(int nIndex);

};
#endif
