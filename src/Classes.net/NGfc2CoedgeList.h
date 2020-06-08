#ifndef NGFC2COEDGELIST_H
#define NGFC2COEDGELIST_H

#include "NGfc2Topology.h"
#include "Gfc2CoedgeList.h"
#include "NGfc2Curve2d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CoedgeList: public NGfc2Topology
{
public:
    NGfc2CoedgeList();
    NGfc2CoedgeList(void* pEntity, bool bOwner);
    int getCoedgesCount();
    void clearCoedges();
    void addCoedges(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoedges(int nIndex);
    NGfc2Curve2d^ getCoedgesPtr(int nIndex);

};
#endif
