#ifndef NGFC2ELLIPSESECTION_H
#define NGFC2ELLIPSESECTION_H

#include "NGfc2ParameterizedSection.h"
#include "Gfc2EllipseSection.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2EllipseSection: public NGfc2ParameterizedSection
{
public:
    NGfc2EllipseSection();
    NGfc2EllipseSection(void* pEntity, bool bOwner);
    void setSemiAxis1(NGfc2Double dValue);
    NGfc2Double getSemiAxis1();
    bool hasSemiAxis1();
    void setSemiAxis2(NGfc2Double dValue);
    NGfc2Double getSemiAxis2();
    bool hasSemiAxis2();

};
#endif
