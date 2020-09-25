#ifndef GFC2CIRCLEHOLLOWSECTION_H
#define GFC2CIRCLEHOLLOWSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2CircleSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CircleHollowSection: public Gfc2CircleSection
{
GFCENGINE_DEC_OBJECT(Gfc2CircleHollowSection, gfc::engine::CEntity)
public:
    Gfc2CircleHollowSection();
    Gfc2CircleHollowSection(bool bSetSchema);
    void setThickness(const Gfc2Double& dValue);
    Gfc2Double getThickness() const;
    bool hasThickness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
