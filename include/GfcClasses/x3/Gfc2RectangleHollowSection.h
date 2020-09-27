#ifndef GFC2RECTANGLEHOLLOWSECTION_H
#define GFC2RECTANGLEHOLLOWSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RectangleSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RectangleHollowSection: public Gfc2RectangleSection
{
GFCENGINE_DEC_OBJECT(Gfc2RectangleHollowSection, gfc::engine::CEntity)
public:
    Gfc2RectangleHollowSection();
    Gfc2RectangleHollowSection(bool bSetSchema);
    void setThickness(const Gfc2Double& dValue);
    Gfc2Double getThickness() const;
    bool hasThickness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
