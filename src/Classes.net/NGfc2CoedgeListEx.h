#ifndef NGFC2COEDGELISTEX_H
#define NGFC2COEDGELISTEX_H

#include "NGfc2Topology.h"
#include "GfcClasses\x3\Gfc2CoedgeListEx.h"
#include "NGfc2Coedge.h"

public ref class NGfc2CoedgeListEx: public NGfc2Topology
{
public:
    NGfc2CoedgeListEx();
    NGfc2CoedgeListEx(gfc::engine::CEntity* pEntity, bool bOwner);
    int getCoedgeExsCount();
    void clearCoedgeExs();
    void addCoedgeExs(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoedgeExs(int nIndex);

};
#endif
