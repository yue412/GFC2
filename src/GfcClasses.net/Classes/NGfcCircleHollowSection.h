#ifndef NGFCCIRCLEHOLLOWSECTION_H
#define NGFCCIRCLEHOLLOWSECTION_H

#include "NGfcCircleSection.h"
#include "GfcClasses\x3\GfcCircleHollowSection.h"
#include "NTypeDef.h"

public ref class NGfcCircleHollowSection: public NGfcCircleSection
{
public:
    NGfcCircleHollowSection();
    NGfcCircleHollowSection(bool bNoCreate);
    void setThickness(NGfcDouble dValue);
    NGfcDouble getThickness();
    bool hasThickness();

};
#endif
