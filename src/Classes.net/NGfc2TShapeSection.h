#ifndef NGFC2TSHAPESECTION_H
#define NGFC2TSHAPESECTION_H

#include "NGfc2ParameterizedSection.h"
#include "GfcClasses\x3\Gfc2TShapeSection.h"
#include "NTypeDef.h"

public ref class NGfc2TShapeSection: public NGfc2ParameterizedSection
{
public:
    NGfc2TShapeSection();
    NGfc2TShapeSection(void* pEntity, bool bOwner);
    void setWidth(NGfc2Double dValue);
    NGfc2Double getWidth();
    bool hasWidth();
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setThickness1(NGfc2Double dValue);
    NGfc2Double getThickness1();
    bool hasThickness1();
    void setThickness2(NGfc2Double dValue);
    NGfc2Double getThickness2();
    bool hasThickness2();
    void setLeftWidth(NGfc2Double dValue);
    NGfc2Double getLeftWidth();
    bool hasLeftWidth();

};
#endif
