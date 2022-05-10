#ifndef GFCLSHAPESECTION_H
#define GFCLSHAPESECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLShapeSection: public GfcParameterizedSection
{
GFCENGINE_DEC_OBJECT(GfcLShapeSection, gfc::engine::CEntity)
public:
    GfcLShapeSection();
    GfcLShapeSection(bool bSetSchema);
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

};

GFCCLASSES_NAMESPACE_END

#endif
