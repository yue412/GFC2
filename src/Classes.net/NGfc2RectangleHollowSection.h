#ifndef NGFC2RECTANGLEHOLLOWSECTION_H
#define NGFC2RECTANGLEHOLLOWSECTION_H

#include "NGfc2RectangleSection.h"
#include "GfcClasses\x3\Gfc2RectangleHollowSection.h"
#include "NTypeDef.h"

public ref class NGfc2RectangleHollowSection: public NGfc2RectangleSection
{
public:
    NGfc2RectangleHollowSection();
    NGfc2RectangleHollowSection(void* pEntity, bool bOwner);
    void setThickness(NGfc2Double dValue);
    NGfc2Double getThickness();
    bool hasThickness();

};
#endif
