#ifndef GFCTSHAPESECTION_H
#define GFCTSHAPESECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcTShapeSection: public GfcParameterizedSection
{
GFCENGINE_DEC_OBJECT(GfcTShapeSection, gfc::engine::CEntity)
public:
    GfcTShapeSection();
    GfcTShapeSection(bool bSetSchema);
    void setWidth(const GfcDouble& dValue);
    GfcDouble getWidth() const;
    bool hasWidth() const;
    void setHeight(const GfcDouble& dValue);
    GfcDouble getHeight() const;
    bool hasHeight() const;
    void setThickness1(const GfcDouble& dValue);
    GfcDouble getThickness1() const;
    bool hasThickness1() const;
    void setThickness2(const GfcDouble& dValue);
    GfcDouble getThickness2() const;
    bool hasThickness2() const;
    void setLeftWidth(const GfcDouble& dValue);
    GfcDouble getLeftWidth() const;
    bool hasLeftWidth() const;

};

GFCCLASSES_NAMESPACE_END

#endif
