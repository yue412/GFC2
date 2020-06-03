#ifndef GFC2CIRCLEHOLLOWSECTION_H
#define GFC2CIRCLEHOLLOWSECTION_H

#include "GfcClasses.h"
#include "Gfc2CircleSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CircleHollowSection: public Gfc2CircleSection
{
GFCENGINE_DEC_OBJECT(Gfc2CircleHollowSection, gfc2::engine::Entity)
public:
    Gfc2CircleHollowSection();
    Gfc2CircleHollowSection(bool bSetSchema);
    void setThickness(const Gfc2Double& dValue);
    Gfc2Double getThickness() const;
    bool hasThickness() const;

};
#endif
