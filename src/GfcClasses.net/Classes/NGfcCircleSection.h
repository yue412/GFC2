#ifndef NGFCCIRCLESECTION_H
#define NGFCCIRCLESECTION_H

#include "NGfcParameterizedSection.h"
#include "GfcClasses\x3\GfcCircleSection.h"
#include "NTypeDef.h"

public ref class NGfcCircleSection: public NGfcParameterizedSection
{
public:
    NGfcCircleSection();
    NGfcCircleSection(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();

};
#endif
