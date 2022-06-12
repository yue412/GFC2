#ifndef NGFCELLIPSESECTION_H
#define NGFCELLIPSESECTION_H

#include "NGfcParameterizedSection.h"
#include "GfcClasses\x3\GfcEllipseSection.h"
#include "NTypeDef.h"

public ref class NGfcEllipseSection: public NGfcParameterizedSection
{
public:
    NGfcEllipseSection();
    NGfcEllipseSection(gfc::engine::CEntity* pEntity, bool bOwner);
    void setSemiAxis1(NGfcDouble dValue);
    NGfcDouble getSemiAxis1();
    bool hasSemiAxis1();
    void setSemiAxis2(NGfcDouble dValue);
    NGfcDouble getSemiAxis2();
    bool hasSemiAxis2();

};
#endif
