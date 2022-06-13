#ifndef NGFCRECTANGLESECTION_H
#define NGFCRECTANGLESECTION_H

#include "NGfcParameterizedSection.h"
#include "GfcClasses\x3\GfcRectangleSection.h"
#include "NTypeDef.h"

public ref class NGfcRectangleSection: public NGfcParameterizedSection
{
public:
    NGfcRectangleSection();
    NGfcRectangleSection(bool bNoCreate);
    void setXLength(NGfcDouble dValue);
    NGfcDouble getXLength();
    bool hasXLength();
    void setYLength(NGfcDouble dValue);
    NGfcDouble getYLength();
    bool hasYLength();

};
#endif
