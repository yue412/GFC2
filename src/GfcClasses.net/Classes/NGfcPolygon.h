#ifndef NGFCPOLYGON_H
#define NGFCPOLYGON_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcPolygon.h"

public ref class NGfcPolygon: public NGfcTopology
{
public:
    NGfcPolygon();
    NGfcPolygon(bool bNoCreate);

};
#endif