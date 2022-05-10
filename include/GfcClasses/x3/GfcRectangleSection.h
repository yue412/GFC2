#ifndef GFCRECTANGLESECTION_H
#define GFCRECTANGLESECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRectangleSection: public GfcParameterizedSection
{
GFCENGINE_DEC_OBJECT(GfcRectangleSection, gfc::engine::CEntity)
public:
    GfcRectangleSection();
    GfcRectangleSection(bool bSetSchema);
    void setXLength(const GfcDouble& dValue);
    GfcDouble getXLength() const;
    bool hasXLength() const;
    void setYLength(const GfcDouble& dValue);
    GfcDouble getYLength() const;
    bool hasYLength() const;

};

GFCCLASSES_NAMESPACE_END

#endif
