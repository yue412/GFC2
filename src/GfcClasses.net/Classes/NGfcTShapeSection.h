#ifndef NGFCTSHAPESECTION_H
#define NGFCTSHAPESECTION_H

#include "NGfcParameterizedSection.h"
#include "GfcClasses\x3\GfcTShapeSection.h"
#include "NTypeDef.h"

public ref class NGfcTShapeSection: public NGfcParameterizedSection
{
public:
    NGfcTShapeSection();
    NGfcTShapeSection(gfc::engine::CEntity* pEntity, bool bOwner);
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
    void setLeftWidth(NGfcDouble dValue);
    NGfcDouble getLeftWidth();
    bool hasLeftWidth();

};
#endif
