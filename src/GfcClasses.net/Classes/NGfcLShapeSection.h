#ifndef NGFCLSHAPESECTION_H
#define NGFCLSHAPESECTION_H

#include "NGfcParameterizedSection.h"
#include "GfcClasses\x3\GfcLShapeSection.h"
#include "NTypeDef.h"

public ref class NGfcLShapeSection: public NGfcParameterizedSection
{
public:
    NGfcLShapeSection();
    NGfcLShapeSection(bool bNoCreate);
    void setWidth(NGfcDouble dValue);
    NGfcDouble getWidth();
    bool hasWidth();
    void setHeight(NGfcDouble dValue);
    NGfcDouble getHeight();
    bool hasHeight();
    void setThickness1(NGfcDouble dValue);
    NGfcDouble getThickness1();
    bool hasThickness1();
    void setThickness2(NGfcDouble dValue);
    NGfcDouble getThickness2();
    bool hasThickness2();

};
#endif
