#ifndef GFC2RECTANGLESECTION_H
#define GFC2RECTANGLESECTION_H

#include "GfcClasses.h"
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RectangleSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2RectangleSection, gfc2::engine::Entity)
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
#endif
