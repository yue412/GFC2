#ifndef NGFC2RECTANGLESECTION_H
#define NGFC2RECTANGLESECTION_H

#include "NGfc2ParameterizedSection.h"
#include "Gfc2RectangleSection.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RectangleSection: public NGfc2ParameterizedSection
{
public:
    NGfc2RectangleSection();
    NGfc2RectangleSection(void* pEntity, bool bOwner);
    void setXLength(NGfc2Double dValue);
    NGfc2Double getXLength();
    bool hasXLength();
    void setYLength(NGfc2Double dValue);
    NGfc2Double getYLength();
    bool hasYLength();

};
#endif
