#ifndef GFC2RECTANGLESECTION_H
#define GFC2RECTANGLESECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RectangleSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2RectangleSection, gfc::engine::CEntity)
public:
    Gfc2RectangleSection();
    Gfc2RectangleSection(bool bSetSchema);
    void setXLength(const Gfc2Double& dValue);
    Gfc2Double getXLength() const;
    bool hasXLength() const;
    void setYLength(const Gfc2Double& dValue);
    Gfc2Double getYLength() const;
    bool hasYLength() const;

};

GFCCLASSES_NAMESPACE_END

#endif
