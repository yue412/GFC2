#ifndef GFCCIRCLESECTION_H
#define GFCCIRCLESECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCircleSection: public GfcParameterizedSection
{
GFCENGINE_DEC_OBJECT(GfcCircleSection, gfc::engine::CEntity)
public:
    GfcCircleSection();
    GfcCircleSection(bool bSetSchema);
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
