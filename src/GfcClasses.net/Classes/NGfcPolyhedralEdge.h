#ifndef NGFCPOLYHEDRALEDGE_H
#define NGFCPOLYHEDRALEDGE_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcPolyhedralEdge.h"
#include "NTypeDef.h"

public ref class NGfcPolyhedralEdge: public NGfcTopology
{
public:
    NGfcPolyhedralEdge();
    NGfcPolyhedralEdge(bool bNoCreate);
    void setStartVertexIndex(NGfcInteger nValue);
    NGfcInteger getStartVertexIndex();
    bool hasStartVertexIndex();
    void setEndVertexIndex(NGfcInteger nValue);
    NGfcInteger getEndVertexIndex();
    bool hasEndVertexIndex();

};
#endif
