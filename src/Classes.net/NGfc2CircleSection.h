#ifndef NGFC2CIRCLESECTION_H
#define NGFC2CIRCLESECTION_H

#include "NGfc2ParameterizedSection.h"
#include "Gfc2CircleSection.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CircleSection: public NGfc2ParameterizedSection
{
public:
    NGfc2CircleSection();
    NGfc2CircleSection(void* pEntity, bool bOwner);
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();

};
#endif
