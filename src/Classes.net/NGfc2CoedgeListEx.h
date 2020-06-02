#ifndef NGFC2COEDGELISTEX_H
#define NGFC2COEDGELISTEX_H

#include "NGfc2Topology.h"
#include "Gfc2CoedgeListEx.h"
#include "NGfc2Coedge.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CoedgeListEx: public NGfc2Topology
{
public:
    NGfc2CoedgeListEx();
    NGfc2CoedgeListEx(void* pEntity, bool bOwner);
    int getCoedgeExsCount();
    void clearCoedgeExs();
    void addCoedgeExs(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCoedgeExs(int nIndex);
    NGfc2Coedge^ getCoedgeExsPtr(int nIndex);

};
#endif
