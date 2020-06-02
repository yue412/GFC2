#ifndef NGFC2LSHAPESECTION_H
#define NGFC2LSHAPESECTION_H

#include "NGfc2ParameterizedSection.h"
#include "Gfc2LShapeSection.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2LShapeSection: public NGfc2ParameterizedSection
{
public:
    NGfc2LShapeSection();
    NGfc2LShapeSection(void* pEntity, bool bOwner);
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

};
#endif
