#ifndef NGFC2CIRCLEHOLLOWSECTION_H
#define NGFC2CIRCLEHOLLOWSECTION_H

#include "NGfc2CircleSection.h"
#include "Gfc2CircleHollowSection.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CircleHollowSection: public NGfc2CircleSection
{
public:
    NGfc2CircleHollowSection();
    NGfc2CircleHollowSection(void* pEntity, bool bOwner);
    void setThickness(NGfc2Double dValue);
    NGfc2Double getThickness();
    bool hasThickness();

};
#endif
