#ifndef NGFCCOEDGELIST_H
#define NGFCCOEDGELIST_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcCoedgeList.h"
#include "NGfcCurve2d.h"

public ref class NGfcCoedgeList: public NGfcTopology
{
public:
    NGfcCoedgeList();
    NGfcCoedgeList(bool bNoCreate);
    int getCoedgesCount();
    void clearCoedges();
    void addCoedges(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoedges(int nIndex);

};
#endif
