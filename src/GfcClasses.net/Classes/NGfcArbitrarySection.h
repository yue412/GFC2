#ifndef NGFCARBITRARYSECTION_H
#define NGFCARBITRARYSECTION_H

#include "NGfcSection.h"
#include "GfcClasses\x3\GfcArbitrarySection.h"
#include "NGfcPolygon.h"

public ref class NGfcArbitrarySection: public NGfcSection
{
public:
    NGfcArbitrarySection();
    NGfcArbitrarySection(bool bNoCreate);
    void setPoly(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoly();
    bool hasPoly();

};
#endif
