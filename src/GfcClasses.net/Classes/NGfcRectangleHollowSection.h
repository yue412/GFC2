#ifndef NGFCRECTANGLEHOLLOWSECTION_H
#define NGFCRECTANGLEHOLLOWSECTION_H

#include "NGfcRectangleSection.h"
#include "GfcClasses\x3\GfcRectangleHollowSection.h"
#include "NTypeDef.h"

public ref class NGfcRectangleHollowSection: public NGfcRectangleSection
{
public:
    NGfcRectangleHollowSection();
    NGfcRectangleHollowSection(bool bNoCreate);
    void setThickness(NGfcDouble dValue);
    NGfcDouble getThickness();
    bool hasThickness();

};
#endif
