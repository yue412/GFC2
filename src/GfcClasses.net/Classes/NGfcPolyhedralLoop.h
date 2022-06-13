#ifndef NGFCPOLYHEDRALLOOP_H
#define NGFCPOLYHEDRALLOOP_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcPolyhedralLoop.h"
#include "NGfcPolyhedralEdge.h"

public ref class NGfcPolyhedralLoop: public NGfcTopology
{
public:
    NGfcPolyhedralLoop();
    NGfcPolyhedralLoop(bool bNoCreate);
    int getEdgesCount();
    void clearEdges();
    void addEdges(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEdges(int nIndex);

};
#endif
