#ifndef GFCRECTANGLEHOLLOWSECTION_H
#define GFCRECTANGLEHOLLOWSECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRectangleSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRectangleHollowSection: public GfcRectangleSection
{
GFCENGINE_DEC_OBJECT(GfcRectangleHollowSection, gfc::engine::CEntity)
public:
    GfcRectangleHollowSection();
    GfcRectangleHollowSection(bool bSetSchema);
    void setThickness(const GfcDouble& dValue);
    GfcDouble getThickness() const;
    bool hasThickness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
