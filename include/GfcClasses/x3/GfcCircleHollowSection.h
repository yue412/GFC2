#ifndef GFCCIRCLEHOLLOWSECTION_H
#define GFCCIRCLEHOLLOWSECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCircleSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCircleHollowSection: public GfcCircleSection
{
GFCENGINE_DEC_OBJECT(GfcCircleHollowSection, gfc::engine::CEntity)
public:
    GfcCircleHollowSection();
    GfcCircleHollowSection(bool bSetSchema);
    void setThickness(const GfcDouble& dValue);
    GfcDouble getThickness() const;
    bool hasThickness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
